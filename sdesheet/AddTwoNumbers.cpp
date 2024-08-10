Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    if (!head1 && !head2)
        return NULL;
    else if (!head1)
        return  head2;
    else if (!head2)
        return head1;
    int carry = 0;
    int sum = 0;
   	Node *head = NULL;
    Node *end = NULL;
    while (head1 && head2) {
        sum  = head1->data + head2->data + carry;
        carry = sum /10;
        Node *temp = new Node(sum % 10);
        if (head == NULL) {
            head = temp;
            end = temp;
        }
        else {
            end->next = temp;
            end = end->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1) {
        if (carry == 0)
        {
            end->next = head1;
            break;
        }
        sum  = head1->data + carry;
        carry = sum /10;
        Node *temp = new Node(sum % 10);
        end->next = temp;
        end = end->next;
        head1 = head1->next;
    }

     while (head2) {
        if (carry == 0)
        {
            end->next = head2;
            break;
        }
        sum  = head2->data + carry;
        carry = sum /10;
        Node *temp = new Node(sum % 10);
        end->next = temp;
        end = end->next;
        head2 = head2->next;
    }

   if (carry)
   {
       Node *temp = new Node(carry);
       end->next = temp;
       end = end->next;
   }
   return head;
}



Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    if (!head1 && !head2)
        return NULL;
    else if (!head1)
        return  head2;
    else if (!head2)
        return head1;
    int carry = 0;
    int sum = 0;
   	Node *head = new Node(-1);
    Node *end = head;

    while ( (head1 != NULL || head2 != NULL) || carry) {
        sum = 0;
        if (head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2 != NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }

        sum += carry;
        carry = (sum / 10);
        Node *temp = new Node(sum % 10);
        end->next = temp;
        end = end->next;
    }

    return head->next;
}
