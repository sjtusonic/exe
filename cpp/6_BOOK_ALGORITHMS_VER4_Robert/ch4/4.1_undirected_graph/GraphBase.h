

class GraphBase {
	public:
		GraphBase(int v);

		virtual int  V();
		virtual int  E();
		virtual void addEdge(int v,int w);
		virtual vector<int> adj(int v);
		string toString();
		int degree(int v);
		int maxDegree();
		int avgDegree();
		int numberOfSelfLoops();
	private:




};
