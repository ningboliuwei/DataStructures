typedef struct node {
    float coef; //系数
    int expn;   //指数
    struct node *next;
} *Node;

void AddPolyn(Node &Pa, Node &Pb) {
    Node ha = GetHead(Pa);
    Node hb = GetHead(Pb);
    Node qa = NextPos(Pa, ha);
    Node qb = NextPos(Pb, hb);
    while (qa && qb) {
        polynomial a = GetCurElem(qa);
        polynomial b = GetCurElem(qb);
        switch (*cmp(a, b)) {
        case -1: qa = NextPos(Pa, qa); break;
        case 0:
float     sum = a.coef + b.coef;
            if (sum != 0) {
                SetCurElem(qa, sum);
                ha = qa;
            }
            else {
                DelFirst(ha, qa);
                FreeNode(qa);
            }
            DelFirst(hb, qb);
            FreeNode(qb);
            qb = NextPos(pb, hb);
            qa = NextPos(Pa, ha);
            break;
        case 1:
            DelFirst(hb, qb);
            InsFirst(ha, qb);
            qb = NextPos(pb, hb);
            ha = NextPos(pa, ha);
            break;
        } // switch  }//while
        if (!ListEmpty(pb))
            Append(pa, qb);
        FreeNode(hb);
    }
} // AddPolyn

Node *GetHead(Polynomial poly) {
    return poly.head;
}

Node *NextPos(Polynomial poly, Node *pos) {
    if (pos != NULL) {
        return pos->next;
    }
    return NULL;
}

Term GetCurElem(Node *node) {
    if (node != NULL) {
        return node->data;
    }
    return defaultTerm; // 返回一个默认的多项式项
}

int cmp(Term a, Term b) {
    if (a.exponent < b.exponent) {
        return -1;
    } else if (a.exponent > b.exponent) {
        return 1;
    } else {
        return 0;
    }
}

void SetCurElem(Node *node, float coef) {
    if (node != NULL) {
        node->data.coef = coef;
    }
}

void DelFirst(Node **headRef, Node *node) {
    if (headRef != NULL && *headRef != NULL && node != NULL) {
        if (*headRef == node) {
            *headRef = node->next;
        } else {
            Node *temp = *headRef;
            while (temp->next != node) {
                temp = temp->next;
            }
            temp->next = node->next;
        }
    }
}

void FreeNode(Node *node) {
    free(node);
}

void Append(Polynomial *poly, Node *node) {
    Node *last = GetLast(poly->head);
    if (last != NULL) {
        last->next = node;
    } else {
        poly->head = node;
    }
}

Node *GetLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}