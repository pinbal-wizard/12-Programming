using NUnit.Framework;
using Calc;

namespace Project
{
    public class Tests
    {
        [SetUp]
        public void Setup()
        {
            
        }

        [Test]
        public void Test1()
        {
            Assert.Pass();
        }

        [Test]
        public void Test3() 
        {
            Assert.Fail();
        }

        [Test]
        public void AddTwoPositive()
        {
            Calculator calc = new();
            Assert.AreEqual(3, calc.Add(1,2));
        }

        [Test]
        public void AddOnePositiveOneNegative()
        {
            Calculator calc = new();
            Assert.AreEqual(-1, calc.Add(1, -2));
        }

        [Test]
        public void AddTwoNegative()
        {
            Calculator calc = new();
            Assert.AreEqual(-3, calc.Add(-1, -2));
        }

        [Test]
        public void AddZero1()
        {
            Calculator calc = new();
            Assert.AreEqual(-2, calc.Add(0, -2));
        }

        [Test]
        public void AddZero2()
        {
            Calculator calc = new();
            Assert.AreEqual(1, calc.Add(1, 0));
        }

        [Test]
        public void SubTwoPositive()
        {
            Calculator calc = new();
            Assert.AreEqual(-1, calc.Subtract(1, 2));
        }

        [Test]
        public void SubOnePositiveOneNegative()
        {
            Calculator calc = new();
            Assert.AreEqual(3, calc.Subtract(1, -2));
        }

        [Test]
        public void SubTwoNegative()
        {
            Calculator calc = new();
            Assert.AreEqual(1, calc.Subtract(-1, -2));
        }

        [Test]
        public void SubZero1()
        {
            Calculator calc = new();
            Assert.AreEqual(2, calc.Subtract(0, -2));
        }

        [Test]
        public void SubZero2()
        {
            Calculator calc = new();
            Assert.AreEqual(1, calc.Subtract(1, 0));
        }

    }
}