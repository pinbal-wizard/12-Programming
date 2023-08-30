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
        public void Test4()
        {
            Calculator calc = new();


            Assert.AreEqual(3, calc.Add(1,2));
        }

    }
}