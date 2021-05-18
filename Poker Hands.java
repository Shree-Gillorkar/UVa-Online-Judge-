 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.List;
 import java.util.Scanner;
 
/**
  * UVa - 10315 - Poker Hands (http://uva.onlinejudge.org) 
  * @author hwanjoon.choi
  *
  */
 public class Main {
 
        public static final long PAIR = 1000000000000000000L;
         public static final long TWO_PAIR = 2000000000000000000L;        // PAIR + PAIR
         public static final long THREE_OF_A_KIND = 3000000000000000000L; // PAIR + PAIR + Bonus
         public static final long STRAIGHT = 3100000000000000000L;
         public static final long FLUSH = 3200000000000000000L;
         public static final long FULLHOUSE = 4000000000000000000L;       // PAIR + THREE_OF_A_KIND
         public static final long FOURCARDS = 5000000000000000000L;
         public static final long STRAIGHT_FLUSH = 6300000000000000000L;  // STRAIGHT + FLUSH
 
        public static void main(String[] args) {
                 new Main().solveProblem();
         }
 
        public void solveProblem() {
                 final Scanner scanner = new Scanner(System.in);
                 while (scanner.hasNext()) {
                         int[] black = new int[5];
                         int[] white = new int[5];
 
                        // 1. Normalize as a number
                         for(int i=0; i < 5; i++) {
                                 String input = scanner.next();
                                 input = normalize(input);
                                 black[i]= Integer.valueOf(input);
                         }
 
                        for(int i=0; i < 5; i++) {
                                 String input = scanner.next();
                                 input = normalize(input);
                                 white[i] = Integer.valueOf(input);
                         }
 
                        Arrays.sort(black);
                         Arrays.sort(white);
 
                        long bs = getScore(black);
                         long ws = getScore(white);
 
                        if(bs>ws) {
                                 System.out.println("Black wins.");
                         } else if (bs<ws) {
                                 System.out.println("White wins.");
                         } else {
                                 System.out.println("Tie.");
                         }
                 }
                 scanner.close();
         }
 
        private String normalize(String input) {
                 String nor;
                 nor = input.replace("T", "10");
                 nor = nor.replace("J", "11");
                 nor = nor.replace("Q", "12");
                 nor = nor.replace("K", "13");
                 nor = nor.replace("A", "14");
                 nor = nor.replace("S", "1");
                 nor = nor.replace("C", "2");
                 nor = nor.replace("D", "3");
                 nor = nor.replace("H", "4");
                 return nor;
         }
 
        private long makeScore(long base,
                         List<Integer> l){
                 long score = 0L;
                 for(int a:l) {
                         score += a*base;
                         base *= 100;
 
                }
                 return score;
         }
 
        private long getScore(int[] cards) {
                 long score = 0;
                 boolean isConsecutive = false;
                 List<Integer> pairGradeTriple = new ArrayList<Integer>();
                 List<Integer> pairGradeDouble = new ArrayList<Integer>();
                 List<Integer> highCard = new ArrayList<Integer>();
                 boolean isStraight = true;
                 boolean isFlush = true;
 
                for(int i=0; i < cards.length-1; i++) {
                         if(isStraight){
                                 if(cards[i+1]/10 - cards[i]/10 != 1) {
                                         isStraight = false;
                                 }
                         }
 
                        if(isFlush){
                                 if(cards[i+1]%10 != cards[i]%10) {
                                         isFlush = false;
                                 }
                         }
 
                        if(cards[i]/10 == cards[i+1]/10){
                                 score+= PAIR;
                                 if(isConsecutive) {
                                         score+=PAIR; // Bonus
                                         if(pairGradeDouble.size() != 0) {
                                                 pairGradeDouble.remove(pairGradeDouble.size()-1); // remove last
                                                 pairGradeTriple.add(cards[i]/10);
                                         }
                                 } else {
                                         pairGradeDouble.add(cards[i]/10);
                                 }
                                 isConsecutive = true;
 
                        } else {
                                 if(!isConsecutive) {
                                         highCard.add(cards[i]/10);
                                 }
                                 if(i==3) {
                                         highCard.add(cards[i+1]/10);
                                 }
                                 isConsecutive = false;
                         }
                 }
 
                if(isFlush) {
                         score=FLUSH;
                 }
 
                if(isStraight) {
                         score+=STRAIGHT;
                 }
 
                score = score + makeScore(100000000000000L, pairGradeTriple)
                                 + makeScore(10000000000L, pairGradeDouble)
                                 + makeScore(1L, highCard);

                 return score;
         }
 }