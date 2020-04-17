#include "Graph.h"
#include <math.h>
Graph::Graph()
{
}

void Graph::initializeGraph()
{
	//Remember the purpose of this function is to assign the location of each node on the grid, and set up each nodes neighboors.
	//Imagine this grid as creating nodes from left to right.
	//It will assign the x value of nodes until it gets to te maximum x value.
	//If it reaches the maximum x value it should increase on the y so it can set the x values for all nodes in the next row.
	//Its kinda like reading a book. Once you've read to the end of one line your eyes go down to the next.
	//In order to set this up we'll have to first set up some variables.
	//This first one sets the farthest posiible x value.
	int xMaximum = (int)sqrt(nodes.size()) -1;

	//Now here create two variables of type integer; one called xPos and one called yPos.
	//Initialize them both to be 0.
	//This is how we'll keep track of the position the current node should be set to

	//Now we need two loops that can iterate through our list of nodes: one for setting the position of a node, and another for setting up the neighboors for that node
	//I'll leave the first one here for you
	for (std::vector<Node*>::iterator iterNode1 = nodes.begin(); iterNode1 != nodes.end(); ++iterNode1)
	{
		//set each nodes position to be the current x and the current y
		(*iterNode1)->position = { (float)xpos,(float)ypos };
		//This is probably the most confusing part
		//Create another for loop like the one before to set up the nieghboors.
		//Inside it, you'll have to set up a list of conditions to check if a node is a neighboor of our current node
		//You can do this by checking the absolute value of the difference between the position of the node we check in the second loop and our current node.
		// For example a check to see if something is diagonal to us would look like this: 
		/*if (abs((*iterNode2)->position.x - (*iterNode1)->position.x) == 1 && abs((*iterNode2)->position.y - (*iterNode1)->position.y) == 1)
		{
			//do stuff
		}*/
		//If we do this for all nodes, then anything within the distance of 1 will be considered as our neighboor.
		//For things that aren't diagonal, will simply just check to see if it shares the same column or row, and if it has a distance of 1
		//Checking if its on the same column or row is simply just checking to see if its x position or y position is the same as our current nodes
		//Lastly i chaeck to see if a node has not been given a location on the grid by seeing if its x and y are -2. If it is then i use the continue keyword
		//I ended up using 4 if statements for this but you could probably do it with less
		
		//if x position variable is the same as the maximum x position, set x to be 0 and increase the y. Then use continue
		if (xpos == xMaximum)
		{
			xpos = 0;
			ypos++;
			continue;
		}
		//otherwise increase x
		xpos++;
	}
}

void Graph::draw(int scale)
{
	//loop through list of nodes and call draw for each node in list
	for (std::vector<Node*>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
	{
		(*iter)->Draw(scale);
	}
}

void Graph::createGraph(int size)
{
	//create and add nodes to the list of nodes for the amount given in the argument list
	for (int i = 0; i <= size; i++)
	{
		nodes.push_back(new Node({ -2,-2 }));
	}
	//call initialize graph function to organize nodes
	initializeGraph();
}

Node * Graph::findNode(Vector2 pos)
{
	//I loop throughout the entire list and check the position in each node
	for (std::vector<Node*>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
	{
		//if the nodes position is the same as the one given in the argument list i return that node
	}
	//otherwise i return nullptr
}

int Graph::findManhattan(Node * currentNode, Node * goal)
{
	//This is how manhattan distance is calculated. It's optional so I'll leave its implementation here
	return abs(goal->position.x- currentNode->position.x) + abs(goal->position.y - currentNode->position.y);
}
void Graph::reconstructPath(Node *startNode, Node * goalNode)
{
	//this function finds the right path by finding the parent of the goal node and repeating this 
	//process until it reaches the start node

	//First I create a node pointer to act as a iterator
	Node*iter = goalNode->parent;

	//I use a for loop to be sure i can't go on forever. We can use a while loop here,but we know the
	//amount of nodes that can be processed, so a for loop is much safer
	for(int i =0; i< nodes.size();i++)
	{
		//If our iterator is the start node then that means we are at the beginning of our path so we stop here and return
		//Create an if staement that performs this
		//otherwise mark the current node as a part of the path and set the iterator to be its parent
		//You can mark it by setting the nodes isPathNode boolean to be true
		//To access the parent you can do iter->parent;
	}
}
bool Graph::containsNode(std::vector<Node*>* list, Node * nodeToFind)
{
	//I had to look this one up myself so Ill just give it to you
	std::vector<Node*>::iterator it = std::find(list->begin(), list->end(), nodeToFind);
	if (it != list->end())
	{
		return true;
	}
	return false;
}
void Graph::removeNodeFromList(std::vector<Node*>* list, Node * unwantedNode)
{
	//I had to look this one up myself so Ill just give it to you
	auto it = std::find(list->begin(), list->end(), unwantedNode);
	int index = std::distance(list->begin(), it);
	if (index == 0)
	{
		list->erase(list->begin());
		return;
	}
	list->erase(list->begin() + (index - 1));
}
void Graph::sortNodeList(std::vector<Node*>* listPtr)
{
	//You can use bubble sort here to iterate throught the list and organize it by the f score
}
void Graph::AStarSearch(Vector2 startPos, Vector2 endPos)
{
	//I'll leave everything that is exclusive to my implementation of A*
	Node* startNode = findNode(startPos);
	startNode->isStartNode = true;
	Node*goalNode = findNode(endPos);
	goalNode->isGoalNode = true;
	//intialize openlist
	std::vector<Node*> openlist;

	//add the start node to the open list

	std::vector<Node*>* openlistPtr = &openlist;

	//create close list here
	
	//This is how you calculate manhattan distance for the hueristic. Normally you would set the h score to be the hueristic 
	//but since the f score is the total of the g and h score, and the g score is 0 for the start node, I set the f score to just be the h score.
	startNode->fScore = findManhattan(startNode, goalNode);

	//Create a while loop that loops while the size of the openlist is greater than 0
	//Use the sortNodeList function to sort the open list. You can pass in the opentlistPtr as the argument
	//Create a Node* called currentNode. This will keep track of the node we are currently evaluating
	//if current node is the same as the goal node call the reconstruct path function and return
	//if it isn't call the removeNodeFromList function and use openlitPtr and currentNode as the arguments
	//add current node to the closedlist
	//Loop through all edges for the current node
	//You can access edges by using: currentNode->edges
	//In the loop, check if the node at the end of the edge(meaning the current nodes neighboor) is in either the openlist or the closed list
	//You can use the containsNode function and pass in the either the openlist or the closedlist pointer followed by the nodes neighbor.
	//to access the nodes neighboor you can use ("name of edge variable)->target
	//If the statemnet is true the use the continue keyword to continue the loop
	//If the statement is false, set the neighbors gScore to be the currentNodes gScore added to the edges cost
	//to access g score use: ("name of node variable")->gScore
	//Set the h score of the neighbor to be the hueristic if you're using one
	//Set the f score of the neighbor to be the g score of the neighbor added to the hueristic if you're using one
	//Set the parent of the neighbor to be the current node
	//Add the neighbor to the openlist
	
}

