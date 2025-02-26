typedef int Elem; // list base element type
class NodeList { // node-based list
	private:
	// insert Node declaration here. . . (done)
	struct Node { // a node of the list
		Elem elem; // element value
        Node* prev; // previous in list
        Node* next; // next in list
	};
	public:
	// insert Iterator declaration here. . . (done)
	class Iterator { // an iterator for the list
		public:
			Elem& operator*(); // reference to the element
            bool operator==(const Iterator& p) const; // compare positions
            bool operator!=(const Iterator& p) const;
            Iterator& operator++(); // move to next position
            Iterator& operator--(); // move to previous position
            friend class NodeList; // give NodeList access
		private:
			Node* v; // pointer to the node
            Iterator(Node* u); // create from node
	};
	public:
	NodeList(); // default constructor
	int size() const; // list size
	bool empty() const; // is the list empty?
	Iterator begin() const; // beginning position
	Iterator end() const; // (just beyond) last position
	void insertFront(const Elem& e); // insert at front
	void insertBack(const Elem& e); // insert at rear
	void insert(const Iterator& p, const Elem& e); // insert e before p
	void eraseFront(); // remove first
	void eraseBack(); // remove last
	void erase(const Iterator& p); // remove p
	void print();
	Iterator get_iterator(int indx);
	void copy(NodeList::Iterator src_beg, NodeList::Iterator src_end, NodeList::Iterator dst_beg);
	// Destructor
	~NodeList();
	// housekeeping functions omitted. . .
	private: // data members
	int n; // number of items
	Node* header; // head-of-list sentinel
	Node* trailer; // tail-of-list sentinel
};
