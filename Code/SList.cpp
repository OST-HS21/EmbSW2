void SList::insertAt(int pos, double val) {
    assert(pos >= 0 && pos <= nr);
    Node *pEl = new Node;
    pEl->value = val;
    if (pos != 0) // not at head
    {
        Node *p = nodePtr(pos);
        assert(p != nullptr);
        pEl->next = p->next;
        p->next = pEl;
    } else // insert at head
    {
        pEl->next = pHead;
        pHead = pEl;
    }
    ++nr;
}

void SList::deleteAt(int pos) {
    assert(pos > 0 && pos <= nr);
    Node *p = pHead; // cursor
    Node *pDel = p;  // node to be deleted
    if (pos == 1)    // first element
        pHead = pHead->next;
    else {
        for (int i = 1; i < pos - 1; ++i) {
            p = p->next;
        }
        pDel = p->next;
        p->next = pDel->next;
    }
    delete pDel;
    --nr;
}

int SList::search(double val) const {
    // p points to element at pos 1, if not empty
    Node *p = pHead;
    for (int i = 1; p; ++i) {
        if (p->value == val)
            return i;
        p = p->next;
    }
    return 0; // not found
}