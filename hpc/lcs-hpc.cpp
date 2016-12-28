#include "stdafx.h"
//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <vector>
//#include <array>
//#include <string>
//using namespace std;
//
//bool length = false;
//
////callback functions:
//vector<vector<string>> lcs(string, string);
//void backTrack(vector<vector<string>>, string, int, int);
//
//void main(){
//    
//	cout << "Enter the string on the row: ";
//    string str1 = ""; //row string 
//    cin >> str1;
//    str1 = "_" + str1;//add extra character to the string
//    cout << "Enter the string on the column: ";
//    string str2 = ""; //col string 
//    cin >> str2;
//    str2 = "_" + str2;//add extra character to the string
//	vector<vector<string>> myvec = lcs(str1,str2);
//	//print the arrows matrix
//	for(int i = 0; i<myvec.size();i++){
//		for(int j = 0;j<myvec[1].size();j++){
//			cout << myvec[i][j] << " " ;
//		}
//		cout << endl;
//	}
//	backTrack(myvec, str1, str1.size()-1, str2.size()-1);
//	if(length == false)
//		cout << "NO LCS";
//	cout << endl;
//
//    system("pause");
//
//}
//
//vector<vector<string>>  lcs(string str1, string str2){
//
//	//getting each string length 
//	const int len1 = str1.size();
//	const int len2 = str2.size();
//	
//    //define two matricies one for the indecies and the other for the backtracking 
//    vector<vector<int>> indecies(len1, vector<int>(len2));
//	vector<vector<string>> arrows(len1, vector<string>(len2));
//	
//	//initialize the first row and column with 0
//	for(int i = 0; i<len1;i++){
//			indecies[i][0]=0;
//	}
//	for(int i = 0; i<len2;i++){
//			indecies[0][i]=0;
//	}
//	
//	//fill the indecies and arrows arrays
//	for(int i = 1; i< len1;i++){
//		for(int j =1 ; j<len2;j++){
//			//matching condition:
//			if(str1.at(i)== str2.at(j)){
//				indecies[i][j]=indecies[i-1][j-1]+1;
//				arrows[i][j] = "CORNER";
//			}
//			//mismatching condition:
//			else if (str1.at(i) != str2.at(j)){
//				if (indecies[i-1][j] > indecies[i][j-1]){
//					indecies[i][j]=indecies[i-1][j];
//					arrows[i][j] = "UP";
//				}
//				else
//				{
//					indecies[i][j]=indecies[i][j-1];
//					arrows[i][j] = "LEFT";
//				}
//			}
//		}
//	}
//	//printing the arrays out 
//	for(int i = 0; i<indecies.size();i++){
//		for(int j = 0;j<indecies[1].size();j++){
//			cout << indecies[i][j] << " " ;
//		}
//		cout << endl;
//	}
//	/*
//	for(int i = 0; i<arrows.size();i++){
//		for(int j = 0;j<arrows[1].size();j++){
//			cout << arrows[i][j] << " " ;
//		}
//		cout << endl;
//	}*/
//	return arrows;
//	
//}
//
////Backtrack algorithm
//void backTrack(vector<vector<string>> myvec, string str1, int i, int j){	
//	if(i==0 || j==0){
//		return;
//	}
//	if(myvec[i][j] == "CORNER"){
//		backTrack(myvec, str1, i -1,j-1);
//		if (length == false){
//			cout << endl <<"Longest Common Subsequence is ";
//			length = true;
//		}
//		cout << str1.at(i);
//
//	}
//	else if (myvec[i][j] == "UP"){
//		backTrack(myvec, str1, i-1, j);
//	}
//	else if(myvec[i][j] == "LEFT"){
//		backTrack(myvec, str1, i, j-1);
//
//	}
//}
//
//
