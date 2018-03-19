class Tree {
	public:
		Tree(){
			mNodes={};
		}
		Tree(int n){
			mNodes.resize(n);
			for(int i=0;i<mNodes.size();i++)
				mNodes[i]=i;
		}
		void show()
		{
		}
		int addNode(){
			mNodes.push_back(mNodes.size());
			return mNodes.size()-1;
		}
		void addEdge(string f,string t){
			if(std::find(mNodesStr.begin(),mNodesStr.end(),f)==mNodesStr.end())
				mNodesStr.push_back(f);
			if(std::find(mNodesStr.begin(),mNodesStr.end(),t)==mNodesStr.end())
				mNodesStr.push_back(t);
			mEdges.push_back(make_pair(f,t));
		}
	private:
		map<int,string> map_N2S;
		map<string,int> map_S2N;
		vector<int> mNodes;
		vector<string> mNodesStr;
		vector<pair<int,int>> mEdges;
};
