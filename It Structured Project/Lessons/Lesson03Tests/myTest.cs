using NUnit.Framework;
using UnderTest;

namespace Tests;

[TestFixture]
public class Tests
{
    private Calculator _calculator;
    //**BUG**
    //Modulo Inputs are backwards
    //Multiply Rounds Down i think

    [SetUp]
    public void Setup()
    {
        this._calculator = new Calculator();
    }

    /*
    *  You can use this file as a template.
    *  Just add your tests below this comment block
    *  Some tests are already written to guide you.
    *  But do not assume they are in any way complete.
    */

    // Note the use of [TEST] for each test
    [Test]
    public void Add_Int([Values(-10, 10)] int value1, [Values(-10, 10)] int value2)
    {
        Assert.AreEqual((value1 + value2), _calculator.Add(value1, value2));
    }

    [Test]
    public void Add_Float([Values(-10, 10)] float value1, [Values(-10, 10)] float value2)
    {
        Assert.AreEqual((value1 + value2), _calculator.Add(value1, value2));
    }

    [Test]
    public void Sub_Int([Values(-10, 10)] int value1, [Values(-10, 10)] int value2)
    {
        Assert.AreEqual((value1 - value2), _calculator.Subtract(value1, value2));
    }

    [Test]
    public void Sub_Float([Values(-10f, 10f)] float value1, [Values(-10f, 10f)] float value2)
    {
        Assert.AreEqual((value1 - value2), _calculator.Subtract(value1, value2));
    }

    [Test]
    public void Times_Int([Values(-10, 10)] int value1, [Values(-10, 10)] int value2)
    {
        Assert.AreEqual(value1 * value2, _calculator.Multiply(value1, value2));
    }

    [Test]
    public void Times_Float([Values(-10f, 10f)] float value1, [Values(-10f, 10f)] float value2)
    {
        Assert.AreEqual(value1 * value2, _calculator.Multiply(value1, value2));
    }

    [Test]
    public void Times_Fraction([Values(-10, 10)] int value1, [Values(-10, 10)] int value2)   ///Some 0 issue
    {
        Assert.AreEqual(value1 * (1 / value2), _calculator.Multiply(value1, 1 / value2));
        Assert.AreEqual(value2 * (1 / value1), _calculator.Multiply(value2, 1 / value1));
    }

    [Test]
    public void Times_Reciprocal([Values(-10, 10)] double value1)   ///Some 0 issue
    {
        Assert.AreEqual(1, _calculator.Multiply(value1, 1 / value1));
    }

    [Test]
    public void Div_By_Zero()
    {
        try
        {
            _calculator.Divide(10, 0);
        }
        catch
        {
            Assert.Pass();
        }

    }

    [Test]
    public void Modulo([Values(-10f, 10f)] double value1, [Values(-10f, 10f)] double value2)        ///Inputs Are backwards
    {
        // ...or you can have several
        Assert.AreEqual(value1 % value2, _calculator.Modulo(value1, value2));
    }

    [Test]
    public void Regular_Power([Values(-10, 10)] double value1, [Values(-10, 10)] double value2)   ///Some 0 issue  //Round Down Maybe
    {
        Assert.AreEqual(Math.Pow(value1, value2), _calculator.Power(value1, value2));
    }

    [Test]
    public void Square_Root_Negative()
    {
        try
        {
            _calculator.SquareRoot(-1);
        }
        catch
        {
            Assert.Pass();
        }

    }

    [Test]
    public void Square_Root_Double([Values(1f, 1000f)] double value1)   ///Some 0 issue
    {
        Assert.AreEqual(Math.Sqrt(value1), _calculator.SquareRoot(value1));
    }

    [Test]
    public void Sin_Normal()   ///Some 0 issue
    {
        Assert.AreEqual(0, _calculator.Sin(0));
        Assert.AreEqual(0.5, _calculator.Sin(30));
        Assert.AreEqual(1, _calculator.Sin(90));
    }

    [Test]
    public void Cos_Normal()   ///Some 0 issue
    {
        Assert.AreEqual(1, _calculator.Cos(0));
        Assert.AreEqual(0.5, _calculator.Cos(60));
        Assert.AreEqual(0, _calculator.Cos(90));
    }

    [Test]
    public void Tan_Normal()   ///Some 0 issue
    {
        Assert.AreEqual(0, _calculator.Tan(0));
        Assert.AreEqual(1, _calculator.Tan(45));
        
        try
        {
            Assert.AreEqual(0, _calculator.Tan(90));

            Assert.Fail(); //Code should not run as Tan 90 is undefined
        }
        catch (Exception e)
        {
            Assert.Pass();
        }
    }
    
}



    /*
    *  Aim to test every method in the interface.
    *  Cover as many input cases for each method as you can.
    *  E.g., positive/negative numbers/0s.
    *
    *  You can read about the Assert class here:
    *  https://learn.microsoft.com/en-us/dotnet/api/microsoft.visualstudio.testtools.unittesting.assert
    */


public interface ICalculator
{
    // Returns a number representing a + b
    double Add(double a, double b);
    // Returns a number representing a - b
    double Subtract(double a, double b);
    // Returns a number representing a * b
    double Multiply(double a, double b);
    // Returns a number representing a / b
    double Divide(double a, double b);
    // Returns a number representing a % b
    double Modulo(double a, double b);
    // Returns a number representing x ^ y
    double Power(double x, double y);
    // Returns a number representing square root of x
    double SquareRoot(double x);
    // Returns a number representing sin(t)
    double Sin(double t);
    // Returns a number representing cos(t)
    double Cos(double t);
    // Returns a number representing tan(t)
    double Tan(double t);
    // Returns a number representing log{e} of x
    double NaturalLog(double x);
    // Returns a number representing log{b} of x
    double Log(double x, double b);
    // Returns a number representing e ^ x
    double Exp(double x);
    // Returns a matrix representing m + n
    // Where m and n are matrices with the same dimensions
    double[,] AddMatrices(double[,] m, double[,] n);
    // Returns a matrix representing m - n
    // Where m and n are matrices with the same dimensions
    double[,] SubtractMatrices(double[,] m, double[,] n);
    // Returns a matrix representing sm
    // Where s is a real number and m is a matrix
    double[,] ScalarMultiplyMatrix(double s, double[,] m);
    // Returns a matrix representing mn
    // Where such a product can be computed...*
    // *Note to student: you need to look into how matrix multiplication works.
    double[,] MultiplyMatrices(double[,] matrixA, double[,] matrixB);
}