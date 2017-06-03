#include <string>		// defining string operations
#include <algorithm>	//Erase and Replace in string
#include <iostream>	    // standard I/O
#include<sstream>		// to cut between specific chars in string 
#include<cstdlib>	    //Included in the project pdf file to use stof func
using namespace std;

/*All polygons project Functions included here*/
namespace Polygons {
	//Counts Semi Colons and add +1 to count the number of polygons:
	int Polygons_Number(string x)
	{
		int Polygons_Number = 0;
		int length = x.length();

		for (int i = 0; i < length; i++)
		{
			if (x[i] == ';')
			{
				Polygons_Number++;
			}

		}
		return(Polygons_Number + 1);

	}

	//Counts '(' to know the number of points: 
	int Points_Number(string x)
	{
		int points_Number = 0;
		int length = x.length();

		for (int i = 0; i < length; i++)
		{
			if (x[i] == '(')
			{
				points_Number++;
			}

		}
		return(points_Number);

	}

	//to remove "polyogns=" and the two braces "[ , ]":
	string Previous_use(string x)
	{
		int length = x.length();
		for (int i = 0; i < length; i++)
		{
			x.erase(remove(x.begin(), x.end(), '['), x.end());
			x.erase(remove(x.begin(), x.end(), ']'), x.end());
			x.erase(remove(x.begin(), x.end(), '='), x.end());
			x.erase(remove(x.begin(), x.end(), 'p'), x.end());
			x.erase(remove(x.begin(), x.end(), 'o'), x.end());
			x.erase(remove(x.begin(), x.end(), 'l'), x.end());
			x.erase(remove(x.begin(), x.end(), 'y'), x.end());
			x.erase(remove(x.begin(), x.end(), 'g'), x.end());
			x.erase(remove(x.begin(), x.end(), 'o'), x.end());
			x.erase(remove(x.begin(), x.end(), 'n'), x.end());
			x.erase(remove(x.begin(), x.end(), 's'), x.end());
		}
		return(x);
	}

	/*This Following Func Turns the string shapes into array of string numbers*/
	string Shapes_To_String_Array(string x)
	{
		int length = x.length();
		for (int i = 0; i < length; i++)
		{
			replace(x.begin(), x.end(), ';', ','); // replace all ';' to ','
			x.erase(remove(x.begin(), x.end(), ')'), x.end());
			x.erase(remove(x.begin(), x.end(), '('), x.end());
		}

		return(x);
	}

	/*This function gets the highest value of even index numbers to get MAXIMUM X*/
	float Max_X(string x)
	{
		string s = Shapes_To_String_Array(x);
		float Compare = 0;
		float f;
		stringstream ss(s);
		string token;
		int i = 0;
		while (getline(ss, token, ','))
		{

			f = atof(token.c_str());
			if(i==0)
			{
				Compare = f;
			}

			if (i == 0 || i % 2 == 0)
			{

				if (f > Compare)
				{
					Compare = f;
				}
				else
					Compare = Compare;
			}
			i++;

		}
		return(Compare);
	}

	/*This function gets the highest value of odd index numbers to get MAXIMUM Y*/
	float Max_Y(string x)
	{
		string s = Shapes_To_String_Array(x);
		float Compare = 0;
		float f;
		stringstream ss(s);

		string token;
		int i = 0;
		while (getline(ss, token, ','))
		{

			f = atof(token.c_str());

			if (i == 1)
			{
				Compare = f;
			}
			if (i == 1 || i % 2 == !0)
			{

				if (f > Compare)
				{
					Compare = f;
				}
				else
					Compare = Compare;
			}
			i++;

		}
		return(Compare);
	}

	/*This function gets the Min value of even index numbers*/
	float Min_X(string x)
	{
		string s = Shapes_To_String_Array(x);
		float Compare = 0;
		float f;
		stringstream ss(s);

		string token;
		int i = 0;
		while (getline(ss, token, ','))
		{

			f = atof(token.c_str());
			if (i == 0)
			{
				Compare = f;
			}

			if (i == 0 || i % 2 == 0)
			{

				if (f < Compare)
				{
					Compare = f;
				}
				else
					Compare = Compare;
			}
			i++;

		}
		return(Compare);
	}

	/*This function gets the Min value of odd index numbers*/
	float Min_Y(string x)
	{
		string s = Shapes_To_String_Array(x);
		float Compare = 0;
		float f;
		stringstream ss(s);

		string token;
		int i = 0;
		while (getline(ss, token, ','))
		{

			f = atof(token.c_str());
			if (i == 1)
			{
				Compare = f;
			}

			if (i == 1 || i % 2 == !0)
			{

				if (f < Compare)
				{
					Compare = f;
				}
				else
					Compare = Compare;
			}
			i++;

		}
		return(Compare);
	}

	/*This Function takes the string and Lists the polygons by numbers (cout the polygons by order)*/
	void split(string x)
	{
		stringstream ss(x);
		int n = 1;
		string token;

		while (getline(ss, token, ';'))
		{
			cout << "Polygon " << n << " Points: ";
			cout << token << endl;
			n++;

		}

	}

	/*This Func Shows the enclosing rectangle by the use of Max x&y and Min x&y*/
	void Enclosing_Rec(string x)
	{
		cout << "(" << Min_X(x) << "," << Min_Y(x) << ")" << ",";
		cout << "(" << Min_X(x) << "," << Max_Y(x) << ")" << ",";
		cout << "(" << Max_X(x) << "," << Max_Y(x) << ")" << ",";
		cout << "(" << Min_X(x) << "," << Min_Y(x) << ")";
		cout << endl;

	}

	/*Exit when input Quit*/
	bool EXIT(string x)
	{
		if (string::npos != x.find("Quit"))
		{
			return(false);
		}
		else
			return(true);
	}

	//Prints the polygons with (2,1)
	void Polygons_Contain_2_and_1(string x)
	{

		stringstream ss(x);
		int p = Polygons_Number(x);
		int n = 1;
		int arr[100] = { 0 };
		int index = 0;
		string token;
		while (getline(ss, token, ';'))
		{

			if (string::npos != token.find("(2,1)"))
			{
				arr[index] = n;
				index++;
			}

			n++;

		}

		int max = 0;
		for (int i = 0; i < 100; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
			}
		}
		for (int i = 0; i < 100; i++)

		{
			if (arr[i] == max)
			{
				cout << arr[i];
			}
			else
				if (arr[i] != 0)
				{
					cout << arr[i] << ",";
				}
		}
	}

	/*Finds the number of the points on a line segment*/
	int Point_On_Line(string s)
	{
		stringstream ss(s);
		int _X_Y_Detector = 0;
		int n = 1;
		float Xarray[100][100] = { 0 };
		float Yarray[100][100] = { 0 };
		int xindex = 0;
		int yindex = 0;
		int polys = 0;
		string token2;
		string numbs;
		string token;
		float x = 0;
		float y = 0;
		while (getline(ss, token, ';'))
		{
			int xindex = 0;
			int yindex = 0;
			numbs = Shapes_To_String_Array(token);
			stringstream sss(numbs);
			while (getline(sss, token2, ','))
			{

				if (_X_Y_Detector == 0 || _X_Y_Detector % 2 == 0)
				{
					Xarray[polys][xindex] = atof(token2.c_str());
					xindex++;
				}
				else
				{
					Yarray[polys][yindex] = atof(token2.c_str());
					yindex++;
				}

				_X_Y_Detector++;
			}
			polys++;
		}

		int index = 0;
		float dx = 0;
		float dy = 0;
		float slope = 0;
		int redundant = 0;
		float c = 0;
		float slope2 = 0;
		float slope3 = 0;
		polys = 0;
		float lastx = 0;
		float lasty = 0;
		float lastslope = 0;
		float lastslope2 = 0;
		float lastslope3 = 0;
		float lastc = 0;

		float lastx0 = 0;
		float lasty0 = 0;
		float lastslope0 = 0;
		float lastslope20 = 0;
		float lastslope30 = 0;
		float lastc0 = 0;
		/*y=mx+c*/

		for (int i = 0; i < 100; i++)

		{
			index = 0;
			for (int ii = 0; ii < 100; ii++)
			{
				dx = Xarray[polys][index + 2] - Xarray[polys][index];
				dy = Yarray[polys][index + 2] - Yarray[polys][index];
				x = Xarray[polys][index + 1];
				y = Yarray[polys][index + 1];
				c = Yarray[polys][index] - slope*Xarray[polys][index];
				slope = dy / dx;
				slope2 = (y - Yarray[polys][index]) / (x - Xarray[polys][index]);
				slope3 = (Yarray[polys][index + 2] - y) / (Xarray[polys][index + 2] - x);


				if ((dx == 0 && dy == 0))
				{
					if (x == 0 && y == 0 && Xarray[polys][index] == 0 && Yarray[polys][index] == 0 && Xarray[polys][index + 2] == 0 && Yarray[polys][index + 2] == 0)
					{
						break;
					}
					else {
						goto llop;
					}
				}


				if (x == 0 && y == 0 && Xarray[polys][index + 2] == Yarray[polys][index + 2] && Yarray[polys][index + 2] == 0 && Yarray[polys][index + 3] == 0)
				{
					lastx = Xarray[polys][1] - Xarray[polys][index];
					lasty = Yarray[polys][1] - Yarray[polys][index];
					lastslope = lasty / lastx;
					lastslope2 = (Yarray[polys][0] - Yarray[polys][index]) / (Xarray[polys][0] - Xarray[polys][index]);
					lastslope3 = (Yarray[polys][1] - Yarray[polys][0]) / (Xarray[polys][1] - Xarray[polys][0]);
					lastc = Yarray[polys][index] - lastslope*Xarray[polys][index];
					if (Xarray[polys][index] == Xarray[polys][0] && Yarray[polys][index] == Yarray[polys][0])
					{
						redundant++;
					}

					if (lastslope3 == lastslope2)
					{
						if (Yarray[polys][0] - lastslope*Xarray[polys][0] == lastc)
						{
							redundant++;
						}


						else if (lastslope == lastslope2)
						{
							redundant++;
						}
					}
					else if (lastslope == 0)
					{
						if (Yarray[polys][0] == Yarray[polys][index] && Yarray[polys][0] == Yarray[polys][1])
						{
							redundant++;

						}
					}
					else if (lasty == 0 && lastx != 0 && Yarray[polys][0] == Yarray[polys][index] && Yarray[polys][index] == Yarray[polys][1])
					{
						redundant++;

					}


					lastx0 = Xarray[polys][0] - Xarray[polys][index - 1];
					lasty0 = Yarray[polys][0] - Yarray[polys][index - 1];
					lastslope0 = lasty / lastx;
					lastslope20 = (Yarray[polys][index] - Yarray[polys][index - 1]) / (Xarray[polys][index] - Xarray[polys][index - 1]);
					lastslope30 = (Yarray[polys][0] - Yarray[polys][index]) / (Xarray[polys][0] - Xarray[polys][index]);
					lastc0 = Yarray[polys][index - 1] - lastslope0*Xarray[polys][index - 1];

					if (Xarray[polys][index - 1] == Xarray[polys][index] && Yarray[polys][index - 1] == Yarray[polys][index])
					{
						redundant++;
					}
					else if (lastslope30 == lastslope20)
					{
						if (Yarray[polys][index] - lastslope0*Xarray[polys][index] == lastc0)
						{
							redundant++;
						}
						else if (lastslope0 == lastslope20)
						{
							redundant++;
						}

						else if (lastslope0 == 0)
						{
							if (Yarray[polys][index] == Yarray[polys][index - 1] && Yarray[polys][index] == Yarray[polys][0])
							{
								redundant++;

							}
						}
						else if (lasty0 == 0 && lastx0 != 0 && Yarray[polys][index] == Yarray[polys][index - 1] && Yarray[polys][index - 1] == Yarray[polys][0])
						{
							redundant++;

						}

					}









				}


				else if (slope == 0)
				{
					if (y == Yarray[polys][index] && y == Yarray[polys][index + 2])
					{
						redundant++;

					}

				}

				else if ((x == Xarray[polys][index] && y == Yarray[polys][index]))
				{
					redundant++;
				}


				else if (slope2 == slope3)
				{
					if (y == slope*x + c)
					{
						redundant++;
					}
					else if (slope == slope2)
					{
						redundant++;
					}

				}


				else if (dy == 0 && dx != 0 && y == Yarray[polys][index] && Yarray[polys][index] == Yarray[polys][index + 2])
				{
					redundant++;

				}

			llop:
				index++;

			}
			polys++;
		}

		return(redundant);
	}

	/*Detects the triangles regardless the redundant points*/
	void Triangles(string x)
	{
		int points_Number = 0;
		stringstream ss(x);
		int arr[100] = { 0 };
		int index = 0;

		int i = 1;
		string token;
		cout << "triangles are: ";
		while (getline(ss, token, ';'))
		{
			size_t n = count(token.begin(), token.end(), '(');
			if (n - Point_On_Line(token) == 3)
			{
				arr[index] = i;
				index++;
			}
			i++;
		}
		int max = 0;
		for (int i = 0; i < 100; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
			}
		}
		for (int i = 0; i < 100; i++)

		{
			if (arr[i] == max)
			{
				cout << arr[i];
			}
			else
				if (arr[i] != 0)
				{
					cout << arr[i] << ",";
				}
		}
		cout << endl;
	}

	/*Detect the polygons with more than n points*/
	void Polygons_more_Points(string x, string p)
	{
		int points_Number = 0;
		stringstream ss(x);
		int arr[100] = { 0 };
		int index = 0;

		int i = 1;
		string token;
		std::string tmp, rest;

		std::istringstream iss(p);
		iss >> tmp >> tmp;
		std::getline(iss, rest);
		float f = atof(rest.c_str());

		while (getline(ss, token, ';'))
		{
			size_t n = count(token.begin(), token.end(), '(');
			if (n - Point_On_Line(token) > f)
			{
				arr[index] = i;
				index++;
			}
			i++;
		}
		int max = 0;
		for (int i = 0; i < 100; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
			}
		}
		for (int i = 0; i < 100; i++)

		{
			if (arr[i] == max)
			{
				cout << arr[i];
			}
			else
				if (arr[i] != 0)
				{
					cout << arr[i] << ",";
				}
		}
		cout << endl;
	}

	/*Detect the polygons with less than n points*/
	void Polygons_less_Points(string x, string p)
	{
		int points_Number = 0;
		stringstream ss(x);
		int arr[100] = { 0 };
		int index = 0;

		int i = 1;
		string token;
		std::string tmp, rest;

		std::istringstream iss(p);
		iss >> tmp >> tmp;
		std::getline(iss, rest);
		float f = atof(rest.c_str());

		while (getline(ss, token, ';'))
		{
			size_t n = count(token.begin(), token.end(), '(');
			if (n - Point_On_Line(token) < f)
			{
				arr[index] = i;
				index++;
			}
			i++;
		}
		int max = 0;
		for (int i = 0; i < 100; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
			}
		}
		for (int i = 0; i < 100; i++)

		{
			if (arr[i] == max)
			{
				cout << arr[i];
			}
			else
				if (arr[i] != 0)
				{
					cout << arr[i] << ",";
				}
		}
		cout << endl;
	}

	/*Detect the polygons with equal than n points*/
	void Polygons_equal_Points(string x, string p)
	{
		int points_Number = 0;
		stringstream ss(x);
		int arr[100] = { 0 };
		int index = 0;

		int i = 1;
		string token;
		std::string tmp, rest;

		std::istringstream iss(p);
		iss >> tmp >> tmp;
		std::getline(iss, rest);
		float f = atof(rest.c_str());

		while (getline(ss, token, ';'))
		{
			size_t n = count(token.begin(), token.end(), '(');
			if (n - Point_On_Line(token) == f)
			{
				arr[index] = i;
				index++;
			}
			i++;
		}
		int max = 0;
		for (int i = 0; i < 100; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
			}
		}
		for (int i = 0; i < 100; i++)

		{
			if (arr[i] == max)
			{
				cout << arr[i];
			}
			else
				if (arr[i] != 0)
				{
					cout << arr[i] << ",";
				}
		}
		cout << endl;
	}

	/*Prints the points of polygon n*/
	void Split_And_Show(string x, string p)
	{
		stringstream ss(x);
		int n = 1;
		string token;

		std::string tmp, rest;

		std::istringstream iss(p);
		// Read the first two words.    
		iss >> tmp;
		// Read the rest of the line to 'rest'
		std::getline(iss, rest);
		float f = atof(rest.c_str());

		while (getline(ss, token, ';'))
		{

			if (f == n)
			{
				cout << token << endl;

			}
			n++;

		}


	}

	/*Takes a float value and gives a string value*/
	string Convert(float number) {
		std::ostringstream buff;
		buff << number;
		return buff.str();
	}

	/*Prints the points which are common in more than n polygons*/
	void Common_points_More(string s, string p)
	{
		std::string tmp, rest;

		std::istringstream iss(p);
		iss >> tmp>>tmp;
		std::getline(iss, rest);
		int f = atof(rest.c_str());

		int points_Number = 0;
		int index = 0;
		int i = 1;
		string token;
		stringstream sss(s);
		int _X_Y_Detector = 0;
		int n = 1;
		float Xarray[100][100] = { 0 };
		float Yarray[100][100] = { 0 };
		int xindex = 0;
		int yindex = 0;
		int polys = 0;
		string token2;
		string numbs;
		int max = 0;
		int POINT = 0;
		int pointsnum[100] = { 0 };
		int cc = 0;
		while (getline(sss, token, ';'))
		{
			pointsnum[cc] = Points_Number(token);
			cc++;

			int xindex = 0;
			int yindex = 0;
			numbs = Shapes_To_String_Array(token);
			stringstream sss(numbs);
			while (getline(sss, token2, ','))
			{

				if (_X_Y_Detector == 0 || _X_Y_Detector % 2 == 0)
				{
					Xarray[polys][xindex] = atof(token2.c_str());
					xindex++;
				}
				else
				{
					Yarray[polys][yindex] = atof(token2.c_str());
					yindex++;
				}

				_X_Y_Detector++;
			}
			polys++;
		}
		polys = 0;
		index = 0;
		string tot ;
		string add;
		int POINTS ;
		int iindex = 0;
		int checkx = 0;
		int checky = 0;
		for (int i = 0; i < 100; i++)  //for 1 polys
		{
			int i3 = i + 1;
			for (int ii = 0; ii < pointsnum[i]; ii++) //for 1 points

			{
				POINTS = 1;

				for (int iii=i3 ; iii < 100; iii++) //for 2 polys


				{

					for (int ip = 0; ip < pointsnum[iii]; ip++)  //for 2 points
					{

						if (Xarray[i][ii] == Xarray[iii][ip] && Yarray[i][ii] == Yarray[iii][ip])
						{
							POINTS++;
						}

					}
		
				}
				
				if (POINTS > f && checkx != Xarray[i][ii] && checky != Yarray[i][ii])
				{
					/*
					cout<< "(" << Xarray[i][ii] << "," << Yarray[i][ii] << ")";
					*/
					add = '(' + Convert(Xarray[i][ii]) + ',' + Convert(Yarray[i][ii]) + ')'+',';
					tot = tot+add;
					checkx = Xarray[i][ii];
					checky = Yarray[i][ii];

				}

			}

		}
		string st = tot.substr(0, tot.size() - 1);
		cout << st <<endl;

	}

	/*Prints the points which are common in n polygons*/
	void Common_points_Equal(string s, string p)
	{
		std::string tmp, rest;

		std::istringstream iss(p);
		iss >> tmp >> tmp;
		std::getline(iss, rest);
		int f = atof(rest.c_str());

		int points_Number = 0;
		int index = 0;
		int i = 1;
		string token;
		stringstream sss(s);
		int _X_Y_Detector = 0;
		int n = 1;
		float Xarray[100][100] = { 0 };
		float Yarray[100][100] = { 0 };
		int xindex = 0;
		int yindex = 0;
		int polys = 0;
		string token2;
		string numbs;
		int max = 0;
		int POINT = 0;
		int pointsnum[100] = { 0 };
		int cc = 0;
		while (getline(sss, token, ';'))
		{
			pointsnum[cc] = Points_Number(token);
			cc++;

			int xindex = 0;
			int yindex = 0;
			numbs = Shapes_To_String_Array(token);
			stringstream sss(numbs);
			while (getline(sss, token2, ','))
			{

				if (_X_Y_Detector == 0 || _X_Y_Detector % 2 == 0)
				{
					Xarray[polys][xindex] = atof(token2.c_str());
					xindex++;
				}
				else
				{
					Yarray[polys][yindex] = atof(token2.c_str());
					yindex++;
				}

				_X_Y_Detector++;
			}
			polys++;
		}
		polys = 0;
		index = 0;
		string tot;
		string add;
		int POINTS;
		int iindex = 0;
		int checkx = 0;
		int checky = 0;
		for (int i = 0; i < 100; i++)  //for 1 polys
		{
			int i3 = i + 1;
			for (int ii = 0; ii < pointsnum[i]; ii++) //for 1 points

			{
				POINTS = 1;

				for (int iii = i3; iii < 100; iii++) //for 2 polys


				{

					for (int ip = 0; ip < pointsnum[iii]; ip++)  //for 2 points
					{

						if (Xarray[i][ii] == Xarray[iii][ip] && Yarray[i][ii] == Yarray[iii][ip])
						{
							POINTS++;
						}

					}

				}

				if (POINTS == f && checkx != Xarray[i][ii] && checky != Yarray[i][ii])
				{
					/*
					cout<< "(" << Xarray[i][ii] << "," << Yarray[i][ii] << ")";
					*/
					add = '(' + Convert(Xarray[i][ii]) + ',' + Convert(Yarray[i][ii]) + ')' + ',';
					tot = tot + add;
					checkx = Xarray[i][ii];
					checky = Yarray[i][ii];

				}

			}

		}
		string st = tot.substr(0, tot.size() - 1);
		cout << st << endl;

	}

	/*
	float Xarray(string x)
	{

		string token;
		stringstream sss(x);
		int _X_Y_Detector = 0;
		float Xarray[100][100] = { 0 };
		float Yarray[100][100] = { 0 };
		int xindex = 0;
		int yindex = 0;
		int polys = 0;
		string token2;
		string numbs;

		while (getline(sss, token, ';'))
		{
			int xindex = 0;
			int yindex = 0;
			numbs = Shapes_To_String_Array(token);
			stringstream sss(numbs);
			int points = Points_Number(token);
			while (getline(sss, token2, ','))
			{

				if (_X_Y_Detector == 0 || _X_Y_Detector % 2 == 0)
				{
					if (xindex < points)
					{
						Xarray[polys][xindex] = atof(token2.c_str());
						xindex++;
					}
				}
				else
	
				_X_Y_Detector++;
			}
			polys++;
		}
		return(Xarray);
	}

	float Yarray(string x)
	{

		string token;
		stringstream sss(x);
		int _X_Y_Detector = 0;
		float Xarray[100][100] = { 0 };
		float Yarray[100][100] = { 0 };
		int xindex = 0;
		int yindex = 0;
		int polys = 0;
		string token2;
		string numbs;

		while (getline(sss, token, ';'))
		{
			int xindex = 0;
			int yindex = 0;
			numbs = Shapes_To_String_Array(token);
			stringstream sss(numbs);
			int points = Points_Number(token);
			while (getline(sss, token2, ','))
			{

				if (_X_Y_Detector == 1 || _X_Y_Detector % 2 != 0)
				{
					if (xindex < points)
					{
						Yarray[polys][yindex] = atof(token2.c_str());
						yindex++;
					}
				}


				_X_Y_Detector++;
			}
			polys++;
		}

		return(Yarray);

	}

	*/

	/*Prints the points which are common in less than n polygons*/
	void Common_points_Less(string s, string p)
	{
		std::string tmp, rest;

		std::istringstream iss(p);
		iss >> tmp >> tmp;
		std::getline(iss, rest);
		int f = atof(rest.c_str());

		int points_Number = 0;
		int index = 0;
		int i = 1;
		string token;
		stringstream sss(s);
		int _X_Y_Detector = 0;
		int n = 1;
		float Xarray[100][100] = { 0 };
		float Yarray[100][100] = { 0 };
		int xindex = 0;
		int yindex = 0;
		int polys = 0;
		string token2;
		string numbs;
		int max = 0;
		int POINT = 0;
		int pointsnum[100] = { 0 };
		int cc = 0;
		while (getline(sss, token, ';'))
		{
			pointsnum[cc] = Points_Number(token);
			cc++;

			int xindex = 0;
			int yindex = 0;
			numbs = Shapes_To_String_Array(token);
			stringstream sss(numbs);
			while (getline(sss, token2, ','))
			{

				if (_X_Y_Detector == 0 || _X_Y_Detector % 2 == 0)
				{
					Xarray[polys][xindex] = atof(token2.c_str());
					xindex++;
				}
				else
				{
					Yarray[polys][yindex] = atof(token2.c_str());
					yindex++;
				}

				_X_Y_Detector++;
			}
			polys++;
		}
		polys = 0;
		index = 0;
		string tot;
		string add;
		int POINTS;
		int iindex = 0;
		int checkx = 0;
		int checky = 0;
		for (int i = 0; i < 100; i++)  //for 1 polys
		{
			int i3 = i + 1;
			for (int ii = 0; ii < pointsnum[i]; ii++) //for 1 points

			{
				POINTS = 1;

				for (int iii = i3; iii < 100; iii++) //for 2 polys


				{

					for (int ip = 0; ip < pointsnum[iii]; ip++)  //for 2 points
					{

						if (Xarray[i][ii] == Xarray[iii][ip] && Yarray[i][ii] == Yarray[iii][ip])
						{
							POINTS++;
						}

					}

				}

				if (POINTS < f && checkx != Xarray[i][ii] && checky != Yarray[i][ii])
				{
					/*
					cout<< "(" << Xarray[i][ii] << "," << Yarray[i][ii] << ")";
					*/
					add = '(' + Convert(Xarray[i][ii]) + ',' + Convert(Yarray[i][ii]) + ')' + ',';
					tot = tot + add;
					checkx = Xarray[i][ii];
					checky = Yarray[i][ii];

				}

			}

		}
		string st = tot.substr(0, tot.size() - 1);
		cout << st << endl;

	}

	/*This Func Calculates the Perimeter of any shape*/
	void Perimeter(string s, string p)
	{


		string token;
		std::string tmp, rest;

		std::istringstream iss(p);
		iss >> tmp;
		std::getline(iss, rest);
		int f = atof(rest.c_str());

		int points_Number = 0;
		stringstream sss(s);
		int _X_Y_Detector = 0;
		int n = 1;
		float Xarray[100][100] = { 0 };
		float Yarray[100][100] = { 0 };
		int xindex = 0;
		int yindex = 0;
		int polys = 0;
		string token2;
		string numbs;
		int pointsnum[100] = { 0 };
		int cc = 0;
		while (getline(sss, token, ';'))
		{
			pointsnum[cc] = Points_Number(token);
			cc++;

			int xindex = 0;
			int yindex = 0;
			numbs = Shapes_To_String_Array(token);
			stringstream sss(numbs);
			while (getline(sss, token2, ','))
			{

				if (_X_Y_Detector == 0 || _X_Y_Detector % 2 == 0)
				{
					Xarray[polys][xindex] = atof(token2.c_str());
					xindex++;
				}
				else
				{
					Yarray[polys][yindex] = atof(token2.c_str());
					yindex++;
				}

				_X_Y_Detector++;
			}
			polys++;

		}
		double circ = 0;
		double circ_tot = 0;
		for (int point = 0; point < pointsnum[f - 1]; point++)
		{

			if (point == pointsnum[f - 1]-1)
			{
				circ = sqrt((Xarray[f - 1][point] - Xarray[f - 1][0])*(Xarray[f - 1][point] - Xarray[f - 1][0]) + (Yarray[f - 1][point] - Yarray[f - 1][0])*(Yarray[f - 1][point] - Yarray[f - 1][0]));
				circ_tot = circ_tot + circ;
				break;
			}
			else
			{

				circ = sqrt((Xarray[f - 1][point] - Xarray[f - 1][point + 1])*(Xarray[f - 1][point] - Xarray[f - 1][point + 1]) + (Yarray[f - 1][point] - Yarray[f - 1][point + 1])*(Yarray[f - 1][point] - Yarray[f - 1][point + 1]));
				circ_tot = circ_tot + circ;
			}

		}

		cout << circ_tot<<endl;



	}

	/*Detect the polygon inside (1,2),(1,5),(6,5),(6,2)*/
	bool inside_Polygon(string s)
	{
		
			string token;
			stringstream sss(s);
			string x = { '0' };
			float i = 0;
			float xmax = 0;
			float ymax = 0;
			float xmin = 0;
			float ymin = 0;
			while (getline(sss, token, ';'))
			{ 
				i++;
				 xmax = Max_X(token);
				 xmin = Min_X(token);
				 ymax = Max_Y(token);
				 ymin = Min_Y(token);

				if(xmax <= 6 && xmin>=1 && ymax<=5 && ymin >= 2)
				{
				
					x = Convert(i) + ',';
				
				}

			}

			if(x=="0")
			{
				cout << "none"<<endl;
				return (true);

			}
			string st = x.substr(0, x.size() - 1);
			cout << st << endl;
			return (true);
	}
}

int main(void)
{
	/*
	test:
	string _input = ("
polygons=[(2,1),(2,1),(10,10),(4,8);(7,7),(10,10),(6,8),(4,11),(3,10),(2,5),(3,3),(3,3),(2,1),(5,5),(7,7);(10,10),(4,5),(7,8),(6,11),(2,1);(2,1),(2,1),(5,13),(1,11);(0,6),(2,10),(2,12),(-1,13),(-2,11),(-2,7);(-5,5),(-1,5),(-1,10),(-1,10),(5,12);(-4,4),(-2,8),(-2,10),(-4,4);(-5,3),(-3,3),(-1,3),(-3,7),(-5,6);(-2,-1),(-4,4),(-4,-7),(-2,-9),(-2,-4),(-2,-1);(-2,-7),(-4,-10),(-1,-12);(-1,-6),(-3,-6),(-2,-9),(1,-11),(3,-6),(0,-6),(-1,-6);(1,-9),(4,-2),(7,-5),(4,-11);(5,-5),(1,-3),(4,1),(7,2),(7,-6)]
	");
	(2,1),(3,5),(9,5);(3,5),(5,7),(98,5);(5,6),(7,12),(3,5)
	*/
	string _input;
	string x = { '0' }; //For Quit and take operations
	string shapes;
	getline(cin, _input);

	_input = ("polygons=[(3,3),(4,5),(5,4),(3,2);(3,1),(10,10),(3,5),(9,5);(2,1.5),(2,1),(10,10),(4,8);(10,10),(7,7),(6,8),(4,11),(3,10),(2,5),(3,3),(3,3),(2,1),(5,5),(7,7);(4,5),(7,8),(6,11),(2,1);(2,1),(2,1),(5,13),(1,11);(0,6),(2,10),(3,5),(2,12),(-1,13),(-2,11),(-2,7);(3,5),(-5,5),(-1,5),(-1,10),(-1,10),(5,12);(-4,4),(-2,8),(-2,10),(-4,4);(-5,3),(-3,3),(-1,3),(-3,7),(-5,6);(-2,-1),(-4,4),(-4,-7),(-2,-9),(-2,-4),(-2,-1);(-2,-7),(-4,-10),(-1,-12);(-1,-6),(-3,-6),(-2,-9),(1,-11),(3,-6),(0,-6),(-1,-6);(1,-9),(4,-2),(7,-5),(4,-11);(5,-5),(1,-3),(4,1),(7,2),(7,-6)]");
	shapes = Polygons::Previous_use(_input);
	Polygons::split(shapes);
	string str1 = { "Polygon_Points " }; /*the string to Check "Polygon_Points n"*/
	string str2 = { "List_Polygons_Points More " };
	string str3 = { "List_Polygons_Points Less " };
	string str4 = { "List_Polygons_Points Equal " };
	string str5 = { "Polygon_Perimeter " };
	string str6 = { "List_Points_Polygons More " };
	string str7 = { "List_Points_Polygons Equal " };
	string str8 = { "List_Points_Polygons Less " };
	string str9 = { "Inside_Rectangle(1,2),(1,5),(6,5),(6,2)" };


	do
	{
		cin:
		getline(cin, x);

		std::size_t found1 = x.find(str1); /*the times that "Polygon_Points n" are found ----- if zero it's false*/
		std::size_t found2 = x.find(str2); /*the times that points in polygon are found more than n ----- if zero it's false*/
		std::size_t found3 = x.find(str3);  /*the times that points in polygon are found less than n ----- if zero it's false*/
		std::size_t found4 = x.find(str4);  /*the times that points in polygon are found equal than n ----- if zero it's false*/
		std::size_t found5 = x.find(str5);  /*Perimeter detector ----- if zero it's false*/
		std::size_t found6 = x.find(str6);  /*the points repeated in more than n polygon*/
		std::size_t found7 = x.find(str7);   /*the points repeated in n polygon*/
		std::size_t found8 = x.find(str8);   /*the points repeated in less than n polygon*/
		std::size_t found9 = x.find(str9);   /*the points repeated in less than n polygon*/

		if (found2 != std::string::npos)
		{
			Polygons::Polygons_more_Points(shapes, x);
			goto cin;

		}
		if (found3 != std::string::npos)
		{
			Polygons::Polygons_less_Points(shapes, x);
			goto cin;

		}
		if (found4 != std::string::npos)
		{
			Polygons::Polygons_equal_Points(shapes, x);
			goto cin;

		}
		if (found5 != std::string::npos)
		{
			Polygons::Perimeter(shapes, x);
			goto cin;

		}
		if (found6 != std::string::npos)
		{
			Polygons::Common_points_More(shapes, x);
			goto cin;

		}
		if (found7 != std::string::npos)
		{
			Polygons::Common_points_Equal(shapes, x);
			goto cin;
		}
		if (found8 != std::string::npos)
		{
			Polygons::Common_points_Less;
			goto cin;
		
		}
		if (found9 != std::string::npos)
		{
			Polygons::inside_Polygon(shapes);
			goto cin;

		}
		if (found1 != std::string::npos)
		{
			Polygons::Split_And_Show(shapes, x);
			goto cin;
		}

		if(x=="Number_Polygons")
		{
			std::cout << Polygons::Polygons_Number(shapes)<<endl;
			goto cin;

		}
		if(x=="Total_Number_Points")
		{
			std::cout << Polygons::Points_Number(shapes)<<endl;
			goto cin;

		}
		if (x == "Polygons_Enclosing_Point(1,2)")
		{
			Polygons::Polygons_Contain_2_and_1(shapes);
			goto cin;

		}
		if (x == "Maximum_X")
		{
			std::cout<< Polygons::Max_X(shapes)<<endl;
			goto cin;

		}
		if (x == "Minimum_X")
		{
			std::cout << Polygons::Min_X(shapes)<<endl;
			goto cin;

		}
		if (x == "Minimum_Y")
		{
			std::cout << Polygons::Min_Y(shapes)<<endl;
			goto cin;

		}
		if (x == "Maximum_Y")
		{
			std::cout << Polygons::Max_Y(shapes)<<endl;
			goto cin;

		}
		if (x == "Enclosing_Rectangle")
		{
			Polygons::Enclosing_Rec(shapes);
			goto cin;

		}
		if (x == "Total_Redundant_Points")
		{
			std::cout << Polygons::Point_On_Line(shapes) << endl;
			goto cin;

		}
		else if (x == "Quit")
		{
			break;
		}
		else
		{
			std::cout << "None" << endl;
			goto cin;

		}
	

	} while (Polygons::EXIT(x));

	return (0);

}
