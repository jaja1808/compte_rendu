#include "client.h"
#include "product.h"
#include "order.h"
#include "store.h"
#include <iostream>


int main(int argc, char const *argv[]){
/*
// input of product 
    Product iPhone ("IPHONE","apple_corporation",12,890.34);
    Product iMac("iMac","apple_machines",4,2098.45); //creating another product

//creating the first client 
    Client ga("ga","ju","juga",{iMac});  //creating a second client
    Client pure ("Pure","rush","rushJa",{iPhone,iMac});

//creating the first Order
    Order myOrder(pure,{iPhone,iMac},Not_Delivered);

// creating the first sore 
    Store apple("AppleSrore",{iPhone,iMac},{pure,ga},{myOrder});

    //trials
    std::cout << "Test 1" << std::endl;

*/
            // MAIN CODE
                Store newStore;

                newStore.setStoreName("EasyStore");
                newStore.emptyProducts();
                newStore.emptyClients();
                newStore.emptyOrders();

                // THE APPLICATION

                // Main Variables
                int option1;
                int option2;
                int option3;

                // Product
                std::string prodName;
                std::string description;
                int available;
                int quantity;
                float amount;

                // Client
                std::string name;
                std::string prenom;
                std::string id;

                // Order
                std::string stat;
    label:
                do
                {

                    // Main menu
                    std::cout << "Welcome to " << newStore.getStoreName() << std::endl;
                    std::cout << "press:" << std::endl;
                    std::cout << "1.Store Management" << std::endl;
                    std::cout << "2.Client Space" << std::endl;
                    std::cout << "3.Orders Management" << std::endl;
                    std::cout << "4.Quit" << std::endl;

                    std::cin >> option1;

                    switch (option1)
                    {

                    case 1:
                        do
                        {
                            std::cout << "1.Add a new product in store" << std::endl;
                            std::cout << "2.Remove a product in store" << std::endl;
                            std::cout << "3.Add a new client" << std::endl;
                            std::cout << "4.Remove a Client in store" << std::endl;
                            std::cout << "5.Add an order" << std::endl;
                            std::cout << "6.Remove an Order in store" << std::endl;
                            std::cout << "7.Display all products in store" << std::endl;
                            std::cout << "8.Display all orders in store" << std::endl;
                            std::cout << "9.Display all clients of the store" << std::endl;
                            std::cout << "10.Change quantity of product available in Stock" << std::endl;
                            std::cout << "11.Search a Product" << std::endl;
                            std::cout << "12.Search a Client" << std::endl;
                            std::cout << "13.Quit" << std::endl;

                            std::cin >> option2;

                            switch (option2)
                            {

                            case 1:

                                std::cout << "Name of the  product" << std::endl;
                                std::cin >> prodName;
                                std::cout << "Products available for sale" << std::endl;
                                std::cin >> available;
                                std::cout << "Cost of the Product" << std::endl;
                                std::cin >> amount;
                                std::cout << "Product Desription" << std::endl;
                                std::cin >> description;
                                newStore.newProdInStore(prodName, description, amount, available);
                                newStore.displayProducts();

                                break;

                            case 2:

                                std::cout << "Enter the Name of a product to be deleted from the Store" << std::endl;
                                 std::cin >> prodName;
                                 if(newStore.checkProdName(prodName)==true){
                                 newStore.removeProduct(prodName);
                                 newStore.displayProducts();
                                 }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                 }

                                 break;

                             case 3:

                                 std::cout << "Name of the Client" << std::endl;
                                 std::cin >> name;
                                 std::cout << "Surname of the Client" << std::endl;
                                 std::cin >> prenom;
                                 std::cout << "Unique ID of the Client" << std::endl;
                                 std::cin >> id;
                                 std::cout << "Name of the Product to add in the Cart " << std::endl;
                                 std::cin >> prodName;
                                 std::cout << "Quantiy of the Product to add in the Cart " << std::endl;
                                 std::cin >> quantity;

                                 if(newStore.checkIdClients(id)==false){
                                    if(newStore.checkProdName(prodName)==true){
                                 newStore.newClientInStore(name, prenom, id, prodName,quantity);
                                 newStore.displayClients();
                                   }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                  }
                                 }else{
                                 std::cout << "The Id is already assigned ! ID must be unique" << std::endl;
                                 goto label;
                                 }

                                 break;

                             case 4:

                                 std::cout << "Enter an Id of the Client to be deleted from the Store" << std::endl;
                                 std::cin >> id;
                                if( newStore.checkIdClients(id)== true){
                                 newStore.removeClient(id);
                                 newStore.displayClients();
                                  }else{
                                   std::cout << "Not found please put a valid one " << std::endl;
                                    goto label;
                                  }
                                 break;

                             case 5:
                                 do
                                 {
                                     std::cout << "1.Add order with product in Cart" << std::endl;
                                     std::cout << "2.Add order with adding a product to order" << std::endl;
                                     std::cout << "3.Quit" << std::endl;
                                     std::cin >> option3;
                                     switch (option3){

                                     case 1:

                                         std::cout << "Enter ID of the Client" << std::endl;
                                         std::cin >> id;
                                        if( newStore.checkIdClients(id)== true){
                                         newStore.newOrderLinkPanier(id);
                                         newStore.dispalyOrders();
                                         }else{
                                         std::cout << "Not found please put a valid one " << std::endl;
                                         goto label;
                                         }
                                         break;

                                      case 2:

                                         std::cout << "Enter ID of the Client" << std::endl;
                                         std::cin >> id;
                                         std::cout << "Enter the name of the Product" << std::endl;
                                         std::cin >> prodName;
                                         if( newStore.checkIdClients(id)== true && newStore.checkProdName(prodName)==true){
                                         newStore.newOrderNewPr(prodName, id);
                                         newStore.dispalyOrders();
                                         }else{
                                          std::cout << "Not found please put a valid one " << std::endl;
                                          goto label;
                                        }
                                         break;

                                      case 3:
                                         std::cout << "You're leaving this option !" << std::endl;
                                         break;

                                      default:
                                         std::cout << "Invalid Input" << std::endl;
                                         break;
                                     }
                                 } while (option3 != 3);

                                 break;

                             case 6:

                                 std::cout << "Enter ID of the Client" << std::endl;
                                 std::cin >> id;
                                 if( newStore.checkIdClients(id)== true){
                                 newStore.removeOrder(id);
                                 newStore.dispalyOrders();
                                  }else{
                                 std::cout << "Not found please put a valid one " << std::endl;
                                 goto label;
                                 }
                                 break;

                             case 7:
                                 newStore.displayProducts();
                                 break;

                             case 8:
                                 newStore.dispalyOrders();
                                 break;

                             case 9:
                                 newStore.displayClients();
                                 break;

                             case 10:

                                 std::cout << " Enter the name of the product" << std::endl;
                                 std::cin >> prodName;
                                 std::cout << " Enter the new qunatity of the product in Stock" << std::endl;
                                 std::cin >> available;
                                 if(newStore.checkProdName(prodName)==true){
                                 newStore.changeAvailablePct(prodName, available);
                                 newStore.displayProducts();
                                 }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                 }

                                 break;

                             case 11:

                                 std::cout << "Enter the name of the Product" << std::endl;
                                 std::cin >> prodName;
                                 if(newStore.checkProdName(prodName)==true){
                                 newStore.displayThisProduct(prodName);
                                 }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                 }

                                 break;

                             case 12:
                                 std::cout << "Enter the Id of the Client" << std::endl;
                                 std::cin >> id;
                                 if( newStore.checkIdClients(id)== true){
                                 newStore.displayThisClient(id);
                                  }else{
                                  std::cout << "Not found please put a valid one " << std::endl;
                                goto label;
                                }
                                 break;

                             case 13:
                                 std::cout << "You Quit the Store Management!" << std::endl;
                                 break;

                             default:
                                 std::cout << "Invalid Input" << std::endl;
                                 break;
                             }
                         } while (option2 != 13);
                         break;

                     case 2:

                         std::cout << "Enter your Client ID" << std::endl;
                         std::cin >> id;
                         if( newStore.checkIdClients(id)== true){

                      do
                         {

                             std::cout << "1.Add a new product in the cart" << std::endl;
                             std::cout << "2.Remove a product in cart" << std::endl;
                             std::cout << "3.Display all products in cart" << std::endl;
                             std::cout << "4.Make an order of products in Cart" << std::endl;
                             std::cout << "5.Change the quantity of a product in Cart" << std::endl;
                             std::cout << "6.Add a product to your Order" << std::endl;
                             std::cout << "7.Remove a product to your Order" << std::endl;
                             std::cout << "8.Empty your Cart" << std::endl;
                             std::cout << "9.Quit" << std::endl;

                             std::cin >> option2;

                             switch (option2){

                             case 1:

                                 std::cout << "Enter the name of the product you want to add to Cart" << std::endl;
                                 std::cin >> prodName;
                                 std::cout << "Number of the Product to add in the Cart " << std::endl;
                                 std::cin >> quantity;
                                 if(newStore.checkProdName(prodName)==true){
                                 newStore.addPctToCntPnr(id, prodName, quantity);
                                 newStore.getClient(id).displayPanier();
                                 }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                 }

                                 break;

                             case 2:

                                 std::cout << "Enter the name of the product you want to remove from Cart" << std::endl;
                                 std::cin >> prodName;
                                 if(newStore.checkProdName(prodName)==true){
                                 newStore.getClient(id).removePanier(prodName);
                                 newStore.getClient(id).displayPanier();
                                 }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                 }

                                 break;

                             case 3:
                                 newStore.getClient(id).displayPanier();
                                 break;

                             case 4:
                                 newStore.newOrderLinkPanier(id);
                                 newStore.getOrderByClntId(id);
                                 break;

                             case 5:

                                 std::cout << "Enter the products name" << std::endl;
                                 std::cin >> prodName;
                                 std::cout << "Enter the new quantity you want" << std::endl;
                                 std::cin >> available;
                                  if(newStore.checkProdName(prodName)==true){
                                 newStore.changeqtyPctInCntPnr(id, prodName, available);
                                 newStore.getClient(id).displayPanier();
                                 }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                 }

                                 break;

                              case 6:

                                std::cout << "Enter the product's name" << std::endl;
                                 std::cin >> prodName;
                                  if(newStore.checkProdName(prodName)==true){
                                 newStore.getOrderByClntId(id).addProducts(newStore.getProduct(prodName));
                                 newStore.displayOrderOfclient(id);
                                 }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                 }

                                 break;

                              case 7:

                                 std::cout << "Enter the product's name" << std::endl;
                                 std::cin >> prodName;
                                 if(newStore.checkProdName(prodName)==true){
                                 newStore.getOrderByClntId(id).removeProducts(prodName);
                                 newStore.displayOrderOfclient(id);
                                 }else{
                                 std::cout << "Product not Recognised" << std::endl;
                                 goto label;
                                 }

                                 break;

                              case 8:
                                 newStore.getClient(id).emptyPanier();
                                 break;

                             case 9:
                                 std::cout << "You Quit the Client Space" << std::endl;
                                 break;

                             default:
                                 std::cout << "Invalid Input" << std::endl;
                                 break;
                             }
                         } while (option2 != 9);
                         break;
                         }else{
                         std::cout << "Not found please put a valid one " << std::endl;
                         goto label;
                         }

                     case 3:
                     do{
                         std::cout << "1.Display all orders" << std::endl;
                         std::cout << "2.Display an order of a certain client" << std::endl;
                         std::cout << "3.Add a product to a Client's Order" << std::endl;
                         std::cout << "4.Remove a product to your Order" << std::endl;
                         std::cout << "5.Change the Status of an Order" << std::endl;
                         std::cout << "6.Validate an Order of a Client" << std::endl;
                         std::cout << "7.Quit" << std::endl;

                         std::cin >> option2;

                         switch (option2){

                             case 1:
                                 newStore.dispalyOrders();
                              break;

                             case 2:

                              std::cout << "Enter the ID of the Client" << std::endl;
                              std::cin >> id;
                              if( newStore.checkIdClients(id)== true){
                              newStore.displayOrderOfclient(id);
                               }else{
                                std::cout << "Not found please put a valid one " << std::endl;
                                goto label;
                               }
                              break;

                             case 3:

                              std::cout << "Enter the name of the Product" << std::endl;
                              std::cin >> prodName;
                              std::cout << "Enter the ID of the Client" << std::endl;
                              std::cin >> id;
                              if( newStore.checkIdClients(id)== true && newStore.checkProdName(prodName)==true){
                              newStore.getOrderByClntId(id).addProducts(newStore.getProduct(prodName));
                              newStore.displayOrderOfclient(id);
                               }else{
                                std::cout << "Not found please put a valid one " << std::endl;
                                goto label;
                               }
                              break;

                             case 4:

                              std::cout << "Enter the name of the Product" << std::endl;
                              std::cin >> prodName;
                              std::cout << "Enter the ID of the Client" << std::endl;
                              std::cin >> id;
                              if( newStore.checkIdClients(id)== true && newStore.checkProdName(prodName)==true){
                              newStore.getOrderByClntId(id).removeProducts(prodName);
                              newStore.displayOrderOfclient(id);
                               }else{
                               std::cout << "Not found please put a valid one " << std::endl;
                                goto label;
                              }
                              break;

                             case 5:

                                 std::cout << "Enter the ID of the Client " << std::endl;
                                 std::cin >> id;
                                 std::cout << "Enter the new Status" << std::endl;
                                 std::cin >> stat;
                                 if( newStore.checkIdClients(id)== true){
                                 newStore.changeStOrd(id,stat);
                                 newStore.displayOrderOfclient(id);
                                 }else{
                                std::cout << "Not found please put a valid one " << std::endl;
                                goto label;
                             }
                              break;

                             case 6:

                                 std::cout << "Enter the ID of the Client " << std::endl;
                                 std::cin >> id;
                                 if( newStore.checkIdClients(id)== true){
                                 newStore.validateOrder(id);
                                 newStore.displayOrderOfclient(id);
                                  }else{
                                 std::cout << "Not found please put a valid one " << std::endl;
                                 goto label;
                                 }

                              break;

                             case 7:
                                std::cout << "You Quit Order Management" << std::endl;
                              break;

                         default:
                               std::cout << "Invalid Input" << std::endl;
                             break;
                         }
                     } while (option2 != 7);
                         break;

                     case 4:
                         std::cout << "Thank you for shopping with us!" << std::endl;
                         break;

                     default:
                         std::cout << "Invalid Input" << std::endl;
                         break;
                     }
                } while (option1 != 4);


    return 0;
}