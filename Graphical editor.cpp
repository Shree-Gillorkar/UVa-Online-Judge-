#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Fill(char Canvas[252][252], int R, int C, int X, int Y, char color)
{
	char OriginalColor = Canvas[X][Y];
	Canvas[X][Y] = color;
	if (X > 0 && Canvas[X-1][Y] == OriginalColor) Fill(Canvas, R, C, X-1,Y,color);

	if (Y > 0 && Canvas[X][Y-1] == OriginalColor) Fill(Canvas, R, C, X,Y-1,color);

	if (X < C && Canvas[X+1][Y] == OriginalColor) Fill(Canvas, R, C, X+1,Y,color);

	if (Y < R && Canvas[X][Y+1] == OriginalColor) Fill(Canvas, R, C, X,Y+1,color);

	if (X > 0 && Y > 0 && Canvas[X-1][Y-1] == OriginalColor) Fill(Canvas, R, C, X-1,Y-1,color);

	if (X > 0 && Y < R && Canvas[X-1][Y+1] == OriginalColor) Fill(Canvas, R, C, X-1,Y+1,color);

	if (X < C && Y > 0 && Canvas[X+1][Y-1] == OriginalColor) Fill(Canvas, R, C, X+1,Y-1,color);

	if (X < C && Y < R && Canvas[X+1][Y+1] == OriginalColor) Fill(Canvas, R, C, X+1,Y+1,color);

	Canvas[X][Y] = color;

	return;
}

struct bmpFile
{
	string name;
	char data[252][252];
	int C,R;
};
int main()
{

	char Command;
	int C,R;
	char Canvas[252][252] = {'O'};
	vector<bmpFile> results;
	while(cin >> Command && Command != 'X')
	{

		if(Command == 'I')
		{
			cin >> C >> R;
			for (int i=1; i<=R; i++) 
			  for (int j=1; j<=C; j++)
			     Canvas[i][j] = 'O';
		}

		if (Command == 'C')
		{
		   for (int i=1; i<=R; i++)
		      for (int j=1; j<=C; j++) 
		        Canvas[i][j] = 'O';
		}
		if (Command == 'L')
		{
			int X,Y;
			cin  >> X >> Y;
			cin >> Canvas[Y][X];
		}

		if (Command == 'V')
		{
			int X, Y1, Y2;
			char color;
			cin >> X >> Y1 >> Y2 >> color;

			if (Y2 < Y1)
			{
				int tmp = Y1;
				Y1 = Y2;
				Y2 = tmp;
			}

			for (int i=Y1; i <= Y2;i++) 
			   Canvas[i][X] = color;
		}

		if (Command == 'H')
		{
			int Y, X1, X2;
			char color;
			cin >>  X1 >> X2 >> Y >> color;
			if (X2 < X1)
			{
				int tmp = X1;
				X1 = X2;
				X2 = tmp;
			}
			for (int i=X1; i <= X2;i++)
			    Canvas[Y][i] = color;
		}

		if (Command == 'K')
		{
			int Y1, Y2, X1, X2;
			char color;
			cin >> X1 >> Y1 >> X2 >> Y2 >> color;
			for (int i=Y1; i<= Y2; i++) 
			   for (int j=X1; j <= X2;j++) 
			      Canvas[i][j] = color;
		}

		if (Command == 'F')
		{
			int X,Y;
			char color;
			cin >> X >> Y >> color;
			if (color == Canvas[Y][X]) continue;
			Fill(Canvas, C, R, Y, X, color);
		}

		if (Command == 'S')
		{
			string nam;
			//bmpFile * f = new bmpFile;
			cin >> nam;
			cout << nam << endl;
			for (int i=1; i<=R; i++)
			{
				for (int j=1; j <= C; j++)
				   cout << Canvas[i][j];
				cout << endl;
			}

		}

	}

	return 0;
}