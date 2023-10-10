class CustomerManagementSystem
{
    public void AddCustomer(string name, string email, string phone)
    {
        // Complex logic to add a customer to the database
    }
    public void UpdateCustomer(int customerId, string newName, string
newEmail, string newPhone)
    {
        // Complex logic to update customer information in the database
    }

    public void DeleteCustomer(int customerId)
    {
        // Complex logic to delete a customer from the database
    }

    // ... Many more methods related to customer management ...
    // Complex properties related to customer management
    // Complex private fields and methods
    // Constructor and initialization logic
}

class Customer
{
    public void GenerateInvoice()
    {
        // Complex logic to generate an invoice for this customer
    }
    public void SendPromotionalEmail()
    {
        // Complex logic to send promotional emails to this customer
    }
    public void CalculateLifetimeValue()
    {
        // Complex logic to calculate the lifetime value of this customer
    }


    // Complex private fields and methods
    // Constructor and initialization logic
}

/*
 * Separating CustomerManagementSystem into Customer makes
 * This makes anything to do with an individual customer inside the customer class
 * Anything to do with managing or creating customers stays intide CustomerManagementSystem
 * You could split CustomerManagementSystem into 2 smaller 1 for making customers and one for managing
 * Then you could have the factory design pattern
 * 
 * I chose not to do this as it could get too spread out making lasagna code
 * Any customer method could be called in a enumeration loop by CustomerManagementSystem
 * 
 */