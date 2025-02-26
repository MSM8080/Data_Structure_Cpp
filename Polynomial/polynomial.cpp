#include <math.h>
#include "polynomial.h"
#include "node.h"
// ----------------------------------------------------------------------------
Polynomial::Polynomial(Node* h) : head(h)  {}
// ----------------------------------------------------------------------------
Polynomial::Polynomial(const Polynomial& p)
{
    head = p.head;
}
// ----------------------------------------------------------------------------
Polynomial::~Polynomial()
{}
// ----------------------------------------------------------------------------
bool Polynomial::empty() const
{return head == NULL;}
// ----------------------------------------------------------------------------
Node* Polynomial::first_node()
{
    return head;
}
// ----------------------------------------------------------------------------
void Polynomial::print() const
{

    if (empty()==1)
    {
        cout<<"empty!! :("<<endl;
        return;
    }

    Node* temp = head;

    while(temp != NULL)
    {
        // print first element
        if(temp == head)
        {
            if(temp->exp == 0) //X^0
                cout<<temp->coef<<" ";
            else
            {
                if(temp->coef == 1 || temp->coef == -1) // +1 or -1
                {
                    if(temp->coef<0)
                        cout<<"-X^"<<temp->exp<<" ";
                    else
                        cout<<"X^"<<temp->exp<<" ";
                }
                else if(temp->coef == 0)
                    cout<<"";
                else // other coefficeints
                    cout<<temp->coef<<"X^"<<temp->exp<<" ";
            }
        }
        // other elements
        else
        {
            if(temp->exp == 0) //X^0
            {
                if(temp->coef ==0)
                    cout<<"";
                else if(temp->coef < 0)
                    cout<<temp->coef<<" ";
                else
                    cout<<"+ "<<temp->coef<<" ";
            }

            else if(temp->coef < 0) //negative
                cout<<temp->coef<<"X^"<<temp->exp<<" ";
            else if(temp->coef == 0)
                cout<<"";
            else //positive
                cout<<"+ "<<temp->coef<<"X^"<<temp->exp<<" ";
        }
        temp = temp->next;
    }
}
// ----------------------------------------------------------------------------
void Polynomial::remove_term(const int& e)
{
    if(empty())
    {
        cout<<"empty!! :( "<<endl;
        return;
    }
    else if(e == head->exp) // at first
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else
    {
        Node* temp = head->next;
        Node* prev = head;
        while(temp != NULL)
        {
            if(e == temp->exp)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }
            else
                temp = temp->next;
                prev = prev->next;
        }
        cout<<"X^"<<e<<" not found!!"<<endl;
        return;
    }
}
// ----------------------------------------------------------------------------
void Polynomial::add_term(const double& c, const int& e)
{
    if(c ==0)
        return;

    Node * new_node = new Node;
    new_node->exp = e;
    new_node->coef = c;

    //empty
    if (empty()==1)
    {
        head= new_node;
        new_node->next = NULL;
        //cout<<new_node->coef<<" "<<new_node->exp;
        return;
    }
    //one element
    else if(head->next == NULL)
    {
       if(e> head->exp)
       {
           new_node->next = head;
           head = new_node;
       }
       else if(e == head->exp)
       {
           head->coef += c;
       }
       else
       {
           head->next = new_node;
           new_node->next = NULL;
       }
       return;
    }
    //many elements
    else
    {
        Node* temp = head->next;
        Node* prev = head;

        while(temp != NULL)
        {
            // check first node in linked list
            if(e > prev->exp    &&  prev == head)
            {
                new_node->next = prev;
                head = new_node;
                return;
            }
//             check  begging & middle of linked list
            else if (e > temp->exp    &&    e < prev->exp)
            {
                new_node->next = temp;
                prev->next = new_node;
                return;
            }
            // check last node
            else if(e < temp->exp       &&       temp->next == NULL)
            {
                new_node->next = NULL;
                temp->next = new_node;
                return;
            }
            //check existance node by temp
            else if(e == temp->exp)
            {
                if((temp->coef + c)   ==    0)
                    {
                        remove_term(temp->exp);
                        return;
                    }
                else
                    {
                        temp->coef += c;
                        return;
                    }
            }
            //check existance node by prev
            else if(e == prev->exp)
            {
                if((prev->coef + c)   ==    0)
                    {
                        remove_term(prev->exp);
                        return;
                    }
                else
                    {
                        prev->coef += c;
                        return;
                    }
            }
            temp = temp->next;
            prev = prev->next;
        }
    }
}
// ----------------------------------------------------------------------------
Polynomial Polynomial::p_copy() const
{
    Polynomial c;
    Node* temp = head;

    while(temp != NULL)
    {
        c.add_term(temp->coef,temp->exp);
        temp = temp->next;
    }

    return c;
}
// ----------------------------------------------------------------------------
double Polynomial::poly_val(const double& x) const
{
    double sum = 0, term = 0;

    if(empty())
    {
        return sum;
    }
    else
    {
        Node* current = head;
        while(current != NULL)
        {
            term = pow(x,current->exp);
            term *= current->coef;
            sum += term;
            current = current->next;
        }
        return sum;
    }
}
// ----------------------------------------------------------------------------
Polynomial Polynomial::mul_term(const double& c, const int& e) const
{
    if(empty())
    {
        Polynomial r;
        r = p_copy();
        return r;
    }
    else if(c == 0)  // will be empty
    {
        Polynomial r(NULL);
        return r;
    }
    else
    {
        Polynomial r;
        r = p_copy();
        Node* current = r.first_node();
        while(current != NULL)
        {
            current->coef *= c;
            current->exp += e;
            current = current->next;
        }
        return r;
    }
}
// ----------------------------------------------------------------------------
bool Polynomial::operator==(const Polynomial& p) const
{
    Node* current1 = head;
    Node* current2 = p.head;

    if(empty() == 1   &&   p.empty() == 1)
        return true;
    else
        while(current1 != NULL)
        {
            if(current1->exp  ==  current2->exp)
                {
                    if(current1->coef  ==  current2->coef)
                    {
                        current1 = current1->next;
                        current2 = current2->next;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            else
                return false;
        }

    if(current1 == NULL   &&    current2 == NULL)
        return true;
    else
        return false;
}
// ----------------------------------------------------------------------------
bool Polynomial::operator!=(const Polynomial& p) const
{
    Node* current1 = head;
    Node* current2 = p.head;

    if(empty() != p.empty())
        return true;
    else
        while(current1 != NULL)
        {
            if(current1->exp  !=  current2->exp)
                return true;
            else if (current1->coef != current2->coef)
                return true;
            current1 = current1->next;
            current2 = current2->next;
        }

    if(current1 == NULL   &&    current2 == NULL)
        return false;
    else
        return true;
}
// ----------------------------------------------------------------------------
Polynomial Polynomial::operator + (const Polynomial& p) const
{
    Polynomial r;

    if(empty())
        return r = p.p_copy();
    else if(p.empty())
        return p_copy();
    else
    {
        Node* temp1 = head;
        Node* temp2 = p.head;
        while(temp1 != NULL      ||     temp2 != NULL)
        {
            if(temp1 == NULL       &&      temp2 != NULL)
            {
                r.add_term(temp2->coef, temp2->exp);
                temp2 = temp2->next;
            }
            else if(temp1 != NULL       &&      temp2 == NULL)
            {
                r.add_term(temp1->coef,temp1->exp);
                temp1 = temp1->next;
            }
            else if(temp1->exp    >    temp2->exp)
            {
                r.add_term(temp1->coef, temp1->exp);
                temp1 = temp1->next;
            }
            else if(temp1->exp    <     temp2->exp)
            {
                r.add_term(temp2->coef, temp2->exp);
                temp2 = temp2->next;
            }
            else if(temp1->exp    ==    temp2->exp)
            {
                r.add_term(temp1->coef + temp2->coef, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return r;
    }
}
// ----------------------------------------------------------------------------
Polynomial Polynomial::operator - (const Polynomial& p) const
{
    Polynomial r;

    if(empty())
    {
        r = p.p_copy();
        Node* temp = p.head;
        while(temp != NULL)
        {
            temp->coef *= -1;
            temp = temp->next;
        }
        return r;
    }
    else if(p.empty())
        return p_copy();
    else
    {
        Node* temp1 = head;
        Node* temp2 = p.head;
        while(temp1 != NULL      ||     temp2 != NULL)
        {
            if(temp1 == NULL       &&      temp2 != NULL)
            {
                r.add_term(-temp2->coef, temp2->exp);
                temp2 = temp2->next;
            }
            else if(temp1 != NULL       &&      temp2 == NULL)
            {
                r.add_term(temp1->coef,temp1->exp);
                temp1 = temp1->next;
            }
            else if(temp1->exp    >    temp2->exp)
            {
                r.add_term(temp1->coef, temp1->exp);
                temp1 = temp1->next;
            }
            else if(temp1->exp    <     temp2->exp)
            {
                r.add_term(-temp2->coef, temp2->exp);
                temp2 = temp2->next;
            }
            else if(temp1->exp    ==    temp2->exp)
            {
                r.add_term(temp1->coef - temp2->coef, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return r;
    }
}
// ----------------------------------------------------------------------------
Polynomial Polynomial::operator * (const Polynomial& p) const // complexity
{
    if(empty()    ||    p.empty())
    {
        Polynomial r(NULL);
        return r;
    }
    else
    {
        Polynomial r;
        Node* crr1 = head;
        Node* crr2 = p.head;
        while(crr1 != NULL)
        {
            while(crr2 != NULL)
            {
                r.add_term(crr1->coef * crr2->coef,  crr1->exp + crr2->exp);
                crr2 = crr2->next;
            }
            crr2 = p.head;
            crr1 = crr1->next;
        }
        return r;
    }
}
// ----------------------------------------------------------------------------
Polynomial Polynomial::operator / (const Polynomial& divisor) const
{}
// ----------------------------------------------------------------------------
Polynomial Polynomial::operator % (const Polynomial& divisor) const
{}
// ----------------------------------------------------------------------------
Polynomial Polynomial::differentiate () const
{
    if(empty())
    {
        Polynomial r(NULL);
        return r;
    }
    else
    {
        Polynomial r;
        r = p_copy();
        Node* current = r.head;
        while(current != NULL)
        {
            if(current->exp == 0)
                r.remove_term(current->exp);
            else
            {
                current->coef *= current->exp;
                current->exp -= 1;
            }
            current = current->next;
        }
        return r;
    }
}
// ----------------------------------------------------------------------------
Polynomial Polynomial::integrate () const
{
    if(empty())
    {
        Polynomial r(NULL);
        return r;
    }
    else
    {
        Polynomial r;
        r = p_copy();
        Node* current = r.head;
        while(current != NULL)
        {
            current->exp += 1;
            current->coef /= current->exp;
            current = current->next;
        }
        return r;
    }
}
// ----------------------------------------------------------------------------
