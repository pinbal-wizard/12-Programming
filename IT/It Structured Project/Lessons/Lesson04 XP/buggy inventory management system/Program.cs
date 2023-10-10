class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Welcome to the Buggy Inventory System!");
        int option = GetUserOption();


        if (option == 1)
        {
            CalculateTotal();
        }
        else if (option == 2)
        {
            UpdateInventory();
        }
        else if (option == 3)
        {
            PlaceOrder();
        }
        else if (option == 4)
        {
            PrintReport();
        }
        else
        {
            Console.WriteLine("Invalid option selected!");
        }
        Console.WriteLine("Thank you for using the Buggy Inventory System!");
    }
    static int GetUserOption()
    {
        Console.WriteLine("Select an option:");
        Console.WriteLine("1. Calculate Total");
        Console.WriteLine("2. Update Inventory");
        Console.WriteLine("3. Place Order");
        Console.WriteLine("4. Print Report");
        return Convert.ToInt32(Console.ReadLine());
    }

    /// <summary>
    /// the amount and quantity of the order that is calculated are local variables and will not change from order to order
    /// they need to either be a field or proporty to be able to change
    /// </summary>
    static void CalculateTotal()
    {
        // Bug: Incorrect formula for calculating total
        int price = 20;
        int quantity = 5;

        int total = price * quantity;
        Console.WriteLine("Total: " + total);
    }
    /// <summary>
    ///  //currentinventory and oredered quantity are hard coded and are not they would have to be added as a 
    ///  //Field or property to be updated each time
    /// </summary>
    static void UpdateInventory()    {
        // Bug: Inventory not being updated correctly
        int currentInventory = 10;
        int orderedQuantity = 3;
        currentInventory = currentInventory - orderedQuantity;
        Console.WriteLine("Inventory updated: " + currentInventory);
    }

    /// <summary>
    /// orderAmount is a local variable and is make new each time the fucntion in called 
    /// it would have to be made into a field or property 
    /// if orderAmount and orderedQuantitiy represent the same thing one has to be changed
    /// </summary>
    static void PlaceOrder()
    {
        // Bug: Inventory not being updated correctly
        Console.Write("Enter the order amount: ");
        int orderAmount = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Order placed for: " + orderAmount);
    }

    /// <summary>
    /// Theres no references to any other variable so to add any relevant info to the report youd have to shotgun sugery all the fields and proporties into the class
    /// </summary>
    static void PrintReport()
    {
        // Bug: Report not printing correctly - only prints placeholder text
        Console.WriteLine("Report:");
        Console.WriteLine("This is a sample report.");
    }
}