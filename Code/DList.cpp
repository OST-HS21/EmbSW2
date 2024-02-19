void DList::insertAt(int pos, double val) {
    assert(pos >= 0);
    Node *pEl = new Node;
    pEl->value = val;
    if (pos != 0) // not at head
    {
        Node *p = nodePtr(pos);
        assert(p != nullptr);
        pEl->next = p->next;
        pEl->prev = p;
        p->next = pEl;
    } else // insert at head
    {
        pEl->next = pHead;
        pEl->prev = nullptr;
        pHead = pEl;
    }
    if (pEl->next != nullptr) // not last element in list
        pEl->next->prev = pEl;
    ++nr;
}

void DList::deleteAt(int pos) {
    assert(pos > 0 && pos <= nr);
    Node *pDel = nodePtr(pos); // node to be deleted
    assert(pDel != nullptr);
    if (pos == 1) // first element
        pHead = pHead->next;
    else {
        pDel->prev->next = pDel->next;
    }
    if (pDel->next != nullptr) // not last element in list
        pDel->next->prev = pDel->prev;
    delete pDel;
    --nr;
}

int DList::search(double val) const {
    // p points to element at pos 1, if not empty
    Node *p = pHead;
    for (int i = 1; p; ++i) {
        if (p->value == val)
            return i;
        p = p->next;
    }
    return 0; // not found
}