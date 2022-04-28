using namespace std;
class Stock
{   private:
        string symbol;
        string name;
        double previousClosingPrice;
        double currentPrice;
    public:
        Stock(string s, string n):symbol(s),name(n){}
        string getSymbol() const{return symbol;}
        string getName() const{return name;}
        double getPreviousClosingPrice() const{return previousClosingPrice;}
        double getCurrentPrice() const{return currentPrice;}
        void setPreviousClosingPrice(double p){previousClosingPrice=p;}
        void setCurrentPrice(double c){currentPrice=c;}
        double changePercent()const {return currentPrice/previousClosingPrice;}    
};