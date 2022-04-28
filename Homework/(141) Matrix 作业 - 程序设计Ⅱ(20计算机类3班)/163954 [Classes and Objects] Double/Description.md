# [Classes and Objects] Double

# Description
Design a double class named Double to encapsulate the operations of double. The class contains:

A double data field named data. The default values are 0.

A no-arg constructor that creates a default double.

A constructor that creates a double with the specified data.

The get and set functions for all the data fields. (getDouble, setDouble)

A void function add() for current Double plus another Double.

A void function sub() for current Double minus another Double.

A void function mul() for current Double times another Double.

A bool function div() for current Double divided by another Double. The function returns false if another Double is equal to 0.

The definition of Double class is as follow:
```


class Double
{
private:
     double data;
public:

     Double() ;
     Double(double data);
     double getDouble() const;
     void setDouble(double data);
     void add(const Double &other);
     void sub(const Double &other);
     void mul(const Double &other);
     bool div(const Double &other);
};
```

# Input

You don't need to consider the input.

# Output

 You don't need to consider the output.

# Hint

 Submit the implementation of Double class only.

