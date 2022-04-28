# [Classes and Objects] The Stock class

## Description
```
Design a class named Stock that contains:
A string data field named symbol for the stock's symbol.
A string data field named name for the stock's name.
A double data field named previousClosingPrice that stores the stock price for the previous day.
A double data field named  currentPrice that stores the stock price for the current time.
A constructor that creates a stock with specified symbol and name.
The accessor functions for all data fields.
The mutator functions for previousClosingPrice and currentPrice.
A function named changePercent() that returns the precentage changed from previousClosingPrice to currentPrice.
class Stock
{
  public:
    Stock(string symbol, string name);
    string getSymbol() const;
    string getName() const;
    double getPreviousClosingPrice() const;
    double getCurrentPrice() const;
    void setPreviousClosingPrice(double previousClosingPrice);
    void setCurrentPrice(double currentPrice);
    double changePercent();    
};
```

 
