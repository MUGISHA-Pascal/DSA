#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct Recipe{
      string name;
      string instructions;
      Recipe* next;
      vector<string> ingredients;

      Recipe(string n,vector<string> ingr,string instr):name(n),ingredients(ingr),instructions(instr),next(nullptr){}
          };
          class RecipeManager{
            private:
                  Recipe* head;
            public:
                  RecipeManager():head(nullptr){}
                  void addRecipe(string name,vector<string> ingredients,string instructions){
                    Recipe* newRecipe=new Recipe(name,ingredients,instructions);
                    if(!head){
                      head = newRecipe;
                    }else{
                      Recipe* temp =  head;
                      while(temp->next){
                        temp = temp->next;
                      }
                      temp->next= newRecipe;
                      }
                      cout<<"Recipe \""<<name<<"\" added successfully!\n";
                  }
                  void displayAllRecipes() const{
                    if(!head){
                      cout<<"No recipes available. \n";
                      return;
                    }
                    Recipe* temp=head;
                    cout<<"\n All Recipes: \n";
                    while(temp){
                      cout<<"Recipe Name: "<<temp->name<<endl;
                      cout <<"Ingredients: \n";
                      for(const auto& ingredient:temp->ingredients){
                        cout<<" - "<<ingredient<<endl;
                      }
                      cout<<"Instructions: "<<temp->instructions<<endl;
                      cout<<"-------------------\n";
                      temp=temp->next;
                    }
                    }
                  void searchRecipe(const string& name)const{
                    Recipe* temp=head;
                    while(temp){
                      if(temp->name==name){
                        cout<<"Recipe found: \n";
                        cout<<"Recipe Name: "<<temp->name<<endl;
                        cout<<"Ingredients:\n";
                        for(const auto& ingredient : temp->ingredients){
                          cout<<" - "<<ingredient<<endl;
                        }
                        cout<<"Instructions: "<<temp->instructions<<endl;
                        return;
                      }
                      temp=temp->next;
                    }
                    cout<<"Recipe \""<<name<<"\" not found.\n";
                  }
                  void deleteRecipe(const string& name){
                    if(!head){
                    cout<<"No recipes available.\n";
                    return;
                  }
                  if(head->name==name){
                  Recipe* toDelete = head;
                  head=head->next;
                  delete toDelete;
                  cout<<"Recipe \""<<name<<"\" deleted successfully!\n";
                  return;
                  }
                  Recipe* temp=head;
                  while(temp->next && temp->next->name !=name){
                  temp=temp->next;
                  }
                  if(temp->next){
                    Recipe* toDelete = temp->next;
                    temp->next = temp->next->next;
                    delete toDelete;
                    cout<<"Recipe \""<<name<<"\" deleted successfully!\n";
                  }else{
                    cout<<"Recipe \""<<name<<"\" not found.\n";
                  }

                }
                ~RecipeManager(){
                  while(head){
                    Recipe* temp=head;
                    head=head->next;
                    delete  temp;
                  }
                }
          };
int main(){
  RecipeManager manager;
  int choice;
  string name,instructions,ingredient;
  vector<string> ingredients;
  do{
    cout << "\nRecipe Management System\n";
    cout << "1. Add Recipe\n";
    cout << "2. View All Recipes\n";
    cout << "3. Search Recipe by Name\n";
    cout << "4. Delete Recipe by Name\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin>>choice;
    switch(choice){
      case 1:
          cout<<"Enter Recipe Name: ";
          cin.ignore();
          getline(cin,name);
          cout<<"Enter Ingredients (type 'done' to finish):\n";
          ingredients.clear();
          while(true){
            getline(cin,ingredient);
            if(ingredient == "done") break;
            ingredients.push_back(ingredient);
          }
          cout<<"Enter Instructions: ";
          getline(cin,instructions);
          manager.addRecipe(name,ingredients,instructions);
          break;
      case 2:
          manager.displayAllRecipes();
          break;
      case 3:
          cout<<"Enter Recipe Name to Search: ";
          cin.ignore();
          getline(cin,name);
          manager.searchRecipe(name);
          break;
      case 4:
          cout<<"Enter Recipe Name to delete: ";
          cin.ignore();
          getline(cin,name);
          manager.deleteRecipe(name);
          break;
      case 5:
          cout<<"Exiting...\n";
          break;
      default:
          cout<<"Invalid choice. Please try again.\n";
      }

  }while(choice !=5);
  return 0;
}