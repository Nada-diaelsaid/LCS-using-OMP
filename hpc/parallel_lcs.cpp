#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <array>
#include <string>
#include <omp.h>
using namespace std;

bool length = false;

vector<vector<string>>  lcs(string str1, string str2){

	double start; // time before lcs algorithm
    double end; // time after lcs algorithm
    double time1; // total execution time

	//getting each string length 
	const int len1 = str1.size();
	const int len2 = str2.size();
	
    //define two matricies one for the indecies and the other for the backtracking 
    vector<vector<int>> indecies(len1, vector<int>(len2));
	vector<vector<string>> arrows(len1, vector<string>(len2));

	cout << endl;

	start = omp_get_wtime();
	#pragma omp parallel num_threads(8)
	{
	#pragma omp for 
	//initialize the first row and column with 0
	for(int i = 0; i<len1;i++){
			indecies[i][0]=0;
	}
	#pragma omp for 
	for(int i = 0; i<len2;i++){
			indecies[0][i]=0;
	}
	
	//fill the indecies and arrows arrays
	//#pragma omp for 
	for(int i = 1; i< len1;i++){
		for(int j =1 ; j<len2;j++){
			//matching condition:
			if(str1.at(i)== str2.at(j)){
				indecies[i][j]=indecies[i-1][j-1]+1;
				arrows[i][j] = "CORNER";
			}
			//mismatching condition
			else if (str1.at(i) != str2.at(j)){
				if (indecies[i-1][j] > indecies[i][j-1]){
					indecies[i][j]=indecies[i-1][j];
					arrows[i][j] = "UP";
				}
				else
				{
					indecies[i][j]=indecies[i][j-1];
					arrows[i][j] = "LEFT";
				}
			}
		}
	}
	/*#pragma omp for
	//printing the arrays out 
	for(int i = 0; i<indecies.size();i++){
		for(int j = 0;j<indecies[1].size();j++){
			cout << indecies[i][j] << " " ;
		}
		cout << endl;
	}*/
	}
	/*
	for(int i = 0; i<arrows.size();i++){
		for(int j = 0;j<arrows[1].size();j++){
			cout << arrows[i][j] << " " ;
		}
		cout << endl;
	}*/
	end = omp_get_wtime();
    time1 = end - start;
	//printf("Total Time1: %f\n", time1);
	return arrows;
	
}


void backTrack(vector<vector<string>> myvec, string str1, int i, int j, int count){
	
		if(i==0 || j==0){
			
			printf("Length = %d\n",count);
			return;
		}
		if(myvec[i][j] == "CORNER"){
			count++;
			backTrack(myvec, str1, i -1,j-1, count);
			if (length == false){
			cout << endl <<"Longest Common Subsequence is ";
			length = true;
		}
			cout << str1.at(i);
		}
		else if (myvec[i][j] == "UP"){
			backTrack(myvec, str1, i-1, j, count);
		}
		else if(myvec[i][j] == "LEFT"){
			backTrack(myvec, str1, i, j-1, count);

		}
}
void main(){

    double start; // time before algorithm
    double end; // time after algorithm
	double lcstime; // lcs execution time
	double backtracktime; // backtrack execution time
    double time; // total execution time
	int count=0;

	cout << "Enter the string on the column: ";
    string str1 = ""; //col string 
    cin >> str1;
    str1 = "_" + str1;
    cout << "Enter the string on the row: ";
    string str2 = ""; //row string 
    cin >> str2;
    str2 = "_" + str2;

	 
	start = omp_get_wtime();
	vector<vector<string>> myvec = lcs(str1,str2);
	end = omp_get_wtime();
	lcstime = end - start;

	for(int i = 0; i<myvec.size();i++){
		for(int j = 0;j<myvec[1].size();j++){
			cout << myvec[i][j] << " " ;
		}

		cout << endl;
	}

	

	cout<< endl <<" Longest Common Subsequence is ";

	start = omp_get_wtime();

	backTrack(myvec, str1, str1.size()-1, str2.size()-1, count);
	cout<<endl;
	if(length == false)
		cout << " NO LCS"<< endl;

	end = omp_get_wtime();
	backtracktime = end - start;
	time = lcstime + backtracktime;
	cout<<endl;
   printf(" Total Time: %f\n", time);

	cout << endl;
    system("pause");

}