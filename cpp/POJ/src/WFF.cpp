#include "include.top.h"
#include "WFF.class.h"

//static string legalChars="KANCEpqrst";
bool WFF::isLegal()
{
	isLegal(0);


}
bool WFF::isLegal(int level)
{
	int indent=level;
	string prefix="";
	while(indent!=0)
	{
		prefix+="   ";
		indent--;
	}
	//PRINT_DEBUG_INFO();
	cout<<prefix<<"calling WFF::isLegal("<<mForm<<","<<level<<")"<<endl;

	for (auto c:mForm) // search illegal chars
	{
		bool flag_match=0;
		if(legalChars.find(c)==std::string::npos)
		{
			cout<<prefix<<"mForm has illegal char:"<<endl;
			PRINTVAR(mForm);
			//assert(0);
			return false;
		}
	}

	// parse Op and Arg
	if(mForm.size()==0)
		return false;
	else if(mForm.size()==1) // only Arg is legal for 1-char0-WFF
	{
		char c=mForm[0];
		if(islower(c))
		{

			mOp=' ';
			cout<<prefix<<"legal:"<<mForm<<endl;
			return true;
		}
		else
		{
			cout<<prefix<<"illegal:"<<mForm<<endl;
			return false;
		}
	}
	else  // size >1
	{
		char c=mForm[0];
		if(islower(c)) // first char is not Op && size > 1
		{
			cout<<prefix<<"illegal:"<<mForm<<endl;
			return false;
		}
		else if(isupper(mForm[mForm.size()-1])) // last char is Op 
		{
			cout<<prefix<<"illegal:"<<mForm<<endl;
			return false;
		}
		else if(c=='N')
		{
			mOp='N';
			cout<<prefix<<"GOT Op:"<<c<<endl;
			WFF* n_sub=new WFF("");
			n_sub->setMForm(mForm.substr(1,mForm.size()));
			mUnitWFFs.push_back(n_sub);
			return n_sub->isLegal(level+1);
		}
		else  // K,A,C,E
		{
			cout<<prefix<<"GOT Op:"<<c<<endl;
			this->mOp=mForm[0];
			for(int ind=mForm.size()-1;ind!=1;ind--)
			{
				string head=mForm.substr(1,ind-1);
				string tail=mForm.substr(ind,mForm.size());
				//PRINTVAR(head);
				//PRINTVAR(tail);
				WFF *h=new WFF("");
				WFF *t=new WFF("");
				h->setMForm(head);
				t->setMForm(tail);
				PRINTVAR(h->getMForm());
				PRINTVAR(h);
				PRINTVAR(t->getMForm());
				PRINTVAR(t);

				cout<<prefix;
				PRINTVAR_hor(head);
				PRINTVAR_hor(tail);
				cout<<endl;
				if(t->isLegal(level+1)&& h->isLegal(level+1) )
				{
					cout<<prefix<<"legal:"<<mForm<<endl;
					//PRINTVAR(mOp); PRINT_DEBUG_INFO();
					//cout<<"h="<<h.getMForm()<<endl;
					//cout<<"t="<<t.getMForm()<<endl;
					mUnitWFFs.push_back(h);
					mUnitWFFs.push_back(t);
					PRINTVAR(mUnitWFFs.size());
					for(auto i:mUnitWFFs)
						i->show();
					return true;
				}
			}
			cout<<prefix<<"illegal:"<<mForm<<endl;
			return false;
		} // K,A,C,E
	} // size >1
}
void WFF::show()
{
	cout<<mForm<<endl;
}
void WFF::showMUnitWFFs(int indent)
{
	if (mForm.size()>1) {
		string prefix="";
		while(indent!=0)
		{
			prefix+="   ";
			indent--;
		}

		//cout<<prefix<<"*"<<mForm<<"*"<<endl;
		cout<<prefix<<"*"<<mForm<<"=\t";
		//PRINTVAR(this->getMForm());
		cout<<prefix<<this->mOp<<":\t";
		for(auto w:mUnitWFFs)
			cout<<prefix<<w->getMForm()<<"\t";
		cout<<endl;
		//PRINTVAR(mUnitWFFs.size());
		//for(auto i:mUnitWFFs)
			//i->show();
		for(auto w:mUnitWFFs)
		{
			w->showMUnitWFFs(indent+1);
		}
		cout<<endl;
	}
}
#if 0
void WFF::breakIntoUnitWFFs()
{
	cout<<"calling func breakIntoUnitWFFs("<<mForm<<")"<<endl;
	if(mForm.size()==1 && islower(mForm[0]))
	{
		//mUnitWFFs=0;
		return ;
	} 
	else if(mForm[0]=='N')
	{
		WFF* t=new WFF();
		t->setMForm(mForm.substr(1,mForm.size()));
		mUnitWFFs.push_back(t);
		t->breakIntoUnitWFFs();
		// zjc
	}
	else{
		string s="KACE";
		if(s.find(mForm[0]))
		{
			WFF *h=new WFF();;
			WFF *t=new WFF();;
			for(int ind=mForm.size();ind!=1;ind--)
			{
				string head=mForm.substr(1,ind-1);
				string tail=mForm.substr(ind,mForm.size());
				h=head;
				t=tail;
				PRINTVAR_hor(head);
				PRINTVAR_hor(tail);
				cout<<endl;
				//h.show();
				//t.show();
				//cout<<endl;
				if(h.isLegal() && t.isLegal())
				{
					cout<<"head and tail are both legal, break!"<<endl;
					break;
				}
			}
			mUnitWFFs.push_back(h);
			mUnitWFFs.push_back(t);
		}
		else 
		{
			assert(0);
		}
	}
	cout<<"mUnitWFFs:"<<endl;
	for(auto w:mUnitWFFs)
		w.show();

	for(auto w:mUnitWFFs)
		w.breakIntoUnitWFFs();
}
#endif

bool WFF::calcValue(string cond)
{
	bool r;

	if(mForm.size()==1)
	{
		int ind=cond.find(mForm);
		r= cond[ind+1];
		PRINTVAR_hor(r);
		PRINTVAR_hor(cond);
		PRINTVAR_hor(mForm);
	cout<<endl;
		return r;
	}
	assert(legalChars.find(mOp)!=std::string::npos && isupper(mOp));
	if(mOp=='N')
	{
		assert(mUnitWFFs.size()==1);
		r= !mUnitWFFs[0]->calcValue(cond);
	}
	else if(mOp=='K')
	{
		assert(mUnitWFFs.size()==2);
		bool u=mUnitWFFs[0]->calcValue(cond);
		bool v=mUnitWFFs[1]->calcValue(cond);
		r= u&&v;
	}
	else if(mOp=='A')
	{
		assert(mUnitWFFs.size()==2);
		bool u=mUnitWFFs[0]->calcValue(cond);
		bool v=mUnitWFFs[1]->calcValue(cond);
		r= u||v;
	}
	else if(mOp=='C')
	{
		assert(mUnitWFFs.size()==2);
		bool u=mUnitWFFs[0]->calcValue(cond);
		bool v=mUnitWFFs[1]->calcValue(cond);
		r= !u&&v;
	}
	else if(mOp=='E')
	{
		assert(mUnitWFFs.size()==2);
		bool u=mUnitWFFs[0]->calcValue(cond);
		bool v=mUnitWFFs[1]->calcValue(cond);
		r= u==v;
	}
	PRINTVAR_hor(r);
	PRINTVAR_hor(cond);
	PRINTVAR_hor(mForm);
	cout<<endl;
	return r;
}


vector<int> findAllMatchesInString(string str,string subStr)
{
	int pos=str.find(subStr);
	vector<int> positions;
	while(pos!=string::npos)
	{
		positions.push_back(pos);
		pos=str.find(subStr,pos+1);
	}
	return positions;
}

vector<int> findAllUpperLetterInString(string str)
{
	vector<int> positions;
	for(auto it=str.begin();it!=str.end();it++)
	{
		if(isupper(*it))
			positions.push_back(it-str.begin());
	}

	return positions;
}

