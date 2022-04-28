// Problem#: 17644
// Submission#: 4642232
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<string>
using namespace std;

class Stock {
	private:
		string symbol, name;
		double previousClosingPrice, currentPrice;
	public:
		Stock(string Symbol, string Name) {
			symbol = Symbol;
			name = Name;
		}
		string getSymbol() const {
			return symbol;
		}
		string getName() const {
			return name;
		}
		double getPreviousClosingPrice() const{
			return previousClosingPrice;
		}
		double getCurrentPrice() const{
			return currentPrice;
		}
		void setPreviousClosingPrice(double PreviousClosingPrice) {
			previousClosingPrice = PreviousClosingPrice;
		}
		void setCurrentPrice(double CurrentPrice) {
			currentPrice = CurrentPrice;
		}
		double changePercent() const {
			return currentPrice / previousClosingPrice;
		}
};
