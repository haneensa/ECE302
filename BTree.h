//*************************************************************
// Author: Haneen Mohammed& Amal Mukhtar
//
// class BTree
// Binary tree  abstract class
//*************************************************************

#include<iostream>
using namespace std;
 
template <typename Elem> class Tree{
public:
     
    virtual ~Tree() {}
    virtual bool insert(string,string,string,string,double) = 0;
    virtual bool insert(BGate<Elem>&) = 0; 
    virtual Elem evaluate() = 0;
    virtual void setVar(string, Elem) = 0;
    virtual string equation() = 0;
     virtual pair<double, string> slowPath() = 0;
    virtual pair<double, string> slowPath(BNode<Elem>*) = 0;
    virtual int height(BNode<Elem>*) = 0;
    virtual  void deleteNode(BGate<Elem>& ) = 0;
private:
    virtual void setVar(string  , Elem  , BNode<Elem>* ) = 0;
    virtual void setVar2(string  , Elem  , BNode<Elem>* ) = 0;
    virtual Elem getValue() const = 0;
    virtual void evaluate(BNode<Elem>*) = 0;
    virtual Elem compute(string, Elem  , Elem  ) = 0;
    virtual void destroy(BNode<Elem>*) = 0;
    virtual string equation(BNode<Elem>*) = 0;
    virtual  double max(double,double) = 0;
};

//*************************************************************

template <typename Elem>
class BTree : public Tree<Elem> {
protected:
    BNode<Elem> *root;
    
public:
    // post: creates an empty tree
    BTree()
    {
        root = NULL;
    }//end BTree
    //*************************************************************
    
    void destroy(BNode<Elem>* p)
    {
        if (p != NULL)
        {
            destroy(p->left());
            destroy(p->right());
            delete p;
            p = NULL;
         }//end if
    }//end destroy
    //*************************************************************
 
     
    ~BTree() {destroy(root);}
    //*************************************************************

    string equation()
    {
        return equation(root);
    }

    //*************************************************************
    
    //Function to insert Gate in the binary tree.
    //Postcondition: If no node in the binary search tree has the
    // same info as insertItem, a node with the info insertItem
    // is created and inserted in the binary search tree.
    bool insert(BGate<Elem>& addGate)
    {
        BNode<Elem>* current;
        BNode<Elem>* newNode;
    
        newNode = new BNode<Elem>;
        
        newNode->getGate() = addGate;
        newNode->setLeft(NULL);
        newNode->setRight(NULL);
        
        if (root == NULL)    //base condition
        {
            root = newNode;
            return true;
        }//end if
        else
        {
            current = root;
             while(current != NULL)
            {
                if (current->getGate().getIn1() == addGate.getOut() )
                {
                    current->setLeft(newNode);
                    return true;
                }//end if
                else
                    current = current->left();
            }//end while
            
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn1() == addGate.getOut() )
                {
                    current->setLeft(newNode);
                    return true;
                }//end if
                else
                    current = current->right();
            }//end while
            
            current = root;
             while(current != NULL)
            {
                 if (current->getGate().getIn2() == addGate.getOut() )
                {
                    current->setRight(newNode);
                    return true;
                }//end if
                else
                    current = current->right();
            }//end while
            
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn2() == addGate.getOut() )
                {
                    current->setRight(newNode);
                    return true;
                }//end if
                else
                    current = current->left();
            }//end while
        }//end else
    return false;
    }//end insert 
    //*************************************************************

    bool insert(string logic,string input1,string input2,string output,double time)
    {
        BGate<Elem> inGate(logic,input1,input2,output,time);
        insert(inGate);
        return true;
    }//end  insert 
    //*************************************************************
    
    void setVar(string var, Elem e)
    {
        setVar(var, e,root );
    }//end setVar
    //*************************************************************

    Elem evaluate()
    {
        evaluate(root);
        return getValue();
    }// end evaluate
    //*************************************************************

    //Function to delete Gate from the binary tree.
    //Postcondition: If a node with the same info as deleteItem
    // is found, it is deleted from the binary search tree.
        void deleteNode(BGate<Elem>& deleteGate)
    { 
        BNode<Elem>* current;
         if (root == NULL)    //base condition
        { 
            return  ;
        }//end if
        else
        {
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn1() == deleteGate.getOut() )
                {
                    current->setLeft(NULL);
                    return  ;
                }//end if
                else
                    current = current->left();
            }//end while
            
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn1() == deleteGate.getOut() )
                {
                    current->setLeft(NULL);
                    return  ;
                }//end if
                else
                    current = current->right();
            }//end while
            
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn2() == deleteGate.getOut() )
                {
                    current->setRight(NULL);
                    return  ;
                }//end if
                else
                    current = current->right();
            }//end while
            
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn2() == deleteGate.getOut() )
                {
                    current->setRight(NULL);
                    return  ;
                }//end if
                else
                    current = current->left();
            }//end while
        }//end else
        return;
    }//end delete node
    //*************************************************************

    int height(BNode<Elem>* p)
    {
        if (p == NULL)
            return 0;
        else
            return 1 + max(height(p->left()), height(p->right()));
    }
    //*************************************************************

    int height()
    {
        return height(root);
    }
    //*************************************************************

    pair<double, string> slowPath(){
        return slowPath(root);
    }
    //*************************************************************

     pair<double, string> slowPath(BNode<Elem>* root)
    {
        double t = 0;
        string path;
        if (root == NULL)
            return  make_pair(0,path);
        else
        {
            t += max(slowPath(root->left()).first, slowPath(root->right()).first) ;
            if (slowPath(root->left()).first > slowPath(root->right()).first)
                path.append(slowPath(root->left()).second);
            else
                path.append(slowPath(root->right()).second);
        }
        path.append(root->getGate().getType());
        path.append(" ");

        t += root->getGate().getTime();
        return make_pair(t,path);
    }
    //*************************************************************

    
   private:
        
    string equation(BNode<Elem>* root) {
        string eq = "";
         BGate<Elem> gate;
        if (root == NULL)   return ""; // Empty subtree, do nothing
        else
        {
        eq.append(equation(root->left()));
        eq.append(equation(root->right()));
        gate = root->getGate(); 
        eq.append(gate.getOut());
        eq.append(" = ");
        eq.append("( ");
        eq.append(gate.getIn1());
        eq.append(" ");
        eq.append(gate.getType());
        eq.append(" ");
        eq.append(gate.getIn2());
        eq.append(" ). ");
                    return eq;
        }
    }
    //*************************************************************

    void setVar2(string var, Elem e, BNode<Elem>* root ){
        
        if (root == NULL)    //base condition
        {
            return ;
        }//end else if
        else if (root->getGate().getIn1() == var  )
        {
            root->getGate().setData1(e);
            return ;
        }//end else if
        else if (root->getGate().getIn2() == var)
        {
            root->getGate().setData2(e);
            return ;
        }//end else if
        else
            return ;
        
    }//end setvar2
    //*************************************************************

    void setVar(string var, Elem e, BNode<Elem>* root ) {
        if (root == NULL) return; // Empty subtree, do nothing
        setVar2(var,e,root);
        setVar(var, e,root->left());
        setVar(var, e,root->right());
    }//end setVar
    //*************************************************************

    Elem getValue()const
    {
        return root->getGate().getData3();
    } // end getValueOf
    //*************************************************************

    void evaluate(BNode<Elem>* root) {
        Elem output;
        BGate<Elem> gate;
        if (root == NULL) return; // Empty subtree, do nothing
        evaluate(root->left());
        evaluate(root->right());
        gate = root->getGate();
        output = compute(gate.getType(),gate.getData1(), gate.getData2());
        root->getGate().setData3(output);
        setVar(root->getGate().getOut(),output );
    }//end evaluate
    //*************************************************************

    Elem compute(string op, Elem firstOperand, Elem secondOperand)
    {
        if (op == "AND" )
            return AND(firstOperand,secondOperand);
        else if (op == "OR")
            return OR(firstOperand,secondOperand);
        else if (op == "NAND")
            return NAND(firstOperand,secondOperand);
        else
            return NOR(firstOperand,secondOperand);
    } // end compute
    //*************************************************************

 double  max(double x, double y)
    {
            if (x >= y)
                return  x;
            else
                return  y;
    }
    //*************************************************************

}; // end ExpressionTree
