/* Algorithm:
●The meaning of the title: Given the coordinates of n points, it is required to find the shortest path to link these points
●Prime + minimum spanning tree
●Given the coordinates of n points, it is required to find the shortest path. Obviously, the problem of minimum spanning tree can be achieved by using Prime. To find out the length of each side first.
●Extra note: Note that the minimum spanning tree of a set of points in the plane can be found in O(n logn ) by a more complex algorithm. The Delaunay Triangulation of a set of points in the plane can be calculated in O(n logn ) , with O(n) edges in the resultant graph. Since the minimum spanning tree is a subset of the Delaunay triangulation, we can apply any of the MST algorithms on the resultant Delaunay triangulation and thus achieve the O(n logn ) bound.*/

import java.io.*;
import java.util.*;
import java.lang.*;

class Main  {
    public static HashMap<Integer, ArrayList<Freckle>> adjList;
   
    public static Comparator<Freckle> distComparator = new Comparator<Freckle>() {
        public int compare(Freckle f1, Freckle f2) {
            if ((f1.dist - f2.dist) < 0) {
                return -1;
            }
            else if ((f1.dist - f2.dist) > 0) {
                return 1;
            }
           
            return 0;
        }
    };
   
    public static double prim(int start, int numFreckles) {
        Queue<Freckle> queue = new PriorityQueue<Freckle>(numFreckles, distComparator);
        Freckle f = new Freckle(start, 0);
        queue.add(f);
       
        HashSet<Integer> visited = new HashSet<Integer>();
       
        int freckles = 0;
        double sumDist = 0.0;
        while (queue.size() > 0) {
            Freckle curr = queue.poll();
            int currFreckle = curr.f;
            double currDist = curr.dist;
           
            if (visited.contains(currFreckle)) {
                continue;
            }
            visited.add(currFreckle);
           
            freckles++;
            sumDist += Math.sqrt(currDist);
            if (freckles == numFreckles) {
                return sumDist;
            }
           
            ArrayList<Freckle> reachFreckles = adjList.get(currFreckle);
            for (int i = 0; i < reachFreckles.size(); i++) {
                Freckle next = reachFreckles.get(i);
                f = new Freckle(next.f, next.dist);
                queue.add(f);
            }
        }
       
        return -1.0;
    }
   
    public static double distance(Coord f1, Coord f2) {
        return (f2.x-f1.x)*(f2.x-f1.x)+(f2.y-f1.y)*(f2.y-f1.y);
    }
   
    public static void calcDist(Coord[] freckles, int numFreckles) {
        for (int i = 0; i < numFreckles; i++) {
            for (int j = i+1; j < numFreckles; j++) {
                double d = distance(freckles[i], freckles[j]);
                Freckle f = new Freckle(j, d);
                adjList.get(i).add(f);
                f = new Freckle(i, d);
                adjList.get(j).add(f);
            }
        }
    }
   
    public static void process() throws NumberFormatException, IOException {  
        Scanner sc = new Scanner(System.in);
       
        int numCases = sc.nextInt();
        for (int i = 0; i < numCases; i++) {
            if (i > 0) {
                System.out.println(); // blank line between two conseq cases
            }
           
            int numFreckles = sc.nextInt();
            Coord[] freckles = new Coord[numFreckles];
            adjList = new HashMap<Integer, ArrayList<Freckle>>();
            for (int j = 0; j < numFreckles; j++) {
                double x = sc.nextDouble();
                double y = sc.nextDouble();
                Coord c = new Coord(x, y);
                freckles[j] = c;
                adjList.put(j, new ArrayList<Freckle>());
            }

            calcDist(freckles, numFreckles);
           
            double d = prim(0, numFreckles);
           
            System.out.printf("%.2f\n", d);
        }       
                                            
        return;
    }
  
    public static void main(String[] args) throws NumberFormatException, IOException {
        Main m = new Main();
        m.process();

        System.exit(0);
    }
}

class Coord {
    double x;
    double y;
   
    public Coord(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

class Freckle {
    int f;
    double dist;
   
    public Freckle(int f, double dist) {
        this.f = f;
        this.dist = dist;
    }
}
