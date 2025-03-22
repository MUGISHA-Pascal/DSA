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
                  void searchRecipe(const string& name)const{}

          }