class Program
{
    static void Main(string[] args)
    {
        do
        {
            Console.Clear();
            Console.Write("Enter the length of the rectangle / square: ");
            double length;
            if (!double.TryParse(Console.ReadLine(), out length))
            {
                Console.WriteLine("Invalid Input please try again");
                continue;
            }

            Console.Write("Enter the width of the rectangle / square: ");
            double width;
            if (!double.TryParse(Console.ReadLine(), out width))
            {
                Console.WriteLine("Invalid Input please try again");
                continue;
            }

            Console.WriteLine("Select an operation: 1. Calculate Area 2.Calculate Perimeter");
            int choice;
            if (!int.TryParse(Console.ReadLine(), out choice))
            {
                Console.WriteLine("Invalid Input please try again");
                continue;
            }

            switch (choice)
            {
                case 1:
                    double area = length * width;
                    Console.WriteLine("The area is: " + area);
                    break;
                case 2:
                    double perimeter = 2 * (length + width);
                    Console.WriteLine("The perimeter is: " + perimeter);
                    break;
                default:
                    Console.WriteLine("Invalid choice!");
                    break;
            }
            Console.WriteLine("Press any key to continue q to quit");
        } while (Console.ReadKey().Key != ConsoleKey.Q);
    }
}


/*
 * Literally half was the same code
 * Assuming it wanted a loop made it a loop
 *  Used a Do while for the first time in my life thanks mick 😊
 *  
 *  switch case makes adding more cases easier
 *  readability might be better 
 *  
 *  using System.Reflection.Metadata;
 */