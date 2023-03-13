
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Location { INDIA, ABROAD };

struct Destination {
  char name[50];
  int cost;
  float ratings;
  enum Location location;
  struct Destination *left;
  struct Destination *right;
};

struct Destination *createDestination(char *name, int cost,float ratings, enum Location location) {
  struct Destination *destination = (struct Destination*)malloc(sizeof(struct Destination));
  strcpy(destination->name, name);
  destination->cost = cost;
  destination->location = location;
  destination->ratings=ratings;
  destination->left = NULL;
  destination->right = NULL;
  return destination;
}

struct Destination *insertDestination(struct Destination *root, char *name, int cost,float ratings, enum Location location) {
  if (root == NULL) 
  return createDestination(name, cost, ratings,location);
  if (cost <= root->cost)
    root->left = insertDestination(root->left, name, cost,ratings, location);
  else
    root->right = insertDestination(root->right, name, cost,ratings, location);
  return root;
}

void inOrderTraversal(struct Destination *root) {
  if (root == NULL) 
  return;
  inOrderTraversal(root->left);
  printf("Destination: %s, Cost: %d, Ratings=%f Location: %s\n", root->name, root->cost,root->ratings, (root->location == INDIA) ? "India" : "Abroad");
  inOrderTraversal(root->right);
}
void bill(struct Destination *root)
{
  printf("The bill for your destination is\n");

}
int main() {
  struct Destination *root = NULL;

  root = insertDestination(root, "Goa", 5000,5, INDIA);
  root = insertDestination(root, "Manali", 6000,4.5, INDIA);
  root = insertDestination(root, "Paris", 20000,3.2 ,ABROAD);
  root = insertDestination(root, "New York", 25000,4.9, ABROAD);
  root = insertDestination(root, "Thailand", 15000,2.5, ABROAD);

  inOrderTraversal(root);
  
  return 0;
}
