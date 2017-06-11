#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}

#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define PRINT_COUT(p) \
	(::std::cout<<p<<"\t"   )
#define PRINT_ENDL() \
	(::std::cout<<::std::endl)

#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

//#define SIMPLE_LOG

#ifdef SIMPLE_LOG
#define PRINTVAR(a)
#define PRINTVAR_hor(a)
#define PRINT_VECTOR(a)
#define PRINT_VECTOR_hor(a)
#define PRINT_DEBUG_INFO()
#define PRINT_DEBUG_INFO_PREFIX(p)
#endif

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <regex>
#include <assert.h>

#define 	WIN	Result::Win 
#define  LOSS	Result::Loss
#define 	TIE	Result::Tie 

enum class Result { Win, Loss, Tie };
void split(std::string& s, std::string& delim,std::vector< std::string >* ret)
{
	size_t last = 0;
	size_t index=s.find_first_of(delim,last);
	while (index!=std::string::npos)
	{
		ret->push_back(s.substr(last,index-last));
		last=index+1;
		index=s.find_first_of(delim,last);
	}
	if (index-last>0)
	{
		ret->push_back(s.substr(last,index-last));
	}
}

struct PokerHand {
	std::vector<std::string> cards;
	std::string input;
	PokerHand (const char* pokerhand) {
		std::cout<<pokerhand<<std::endl;
		std::string p=pokerhand;
		input=p;
		// poker to hex:
		p=std::regex_replace(p,std::regex("T"),"a");
		p=std::regex_replace(p,std::regex("J"),"b");
		p=std::regex_replace(p,std::regex("Q"),"c");
		p=std::regex_replace(p,std::regex("K"),"d");
		p=std::regex_replace(p,std::regex("A"),"e");
		//
		//std::cout<<p<<std::endl;
		std::string tmp="";
		std::string blank="  ";
		split(p,blank,&cards);
		PRINT_VECTOR_hor(cards);
		sort(cards.begin(),cards.end());

		PRINT_VECTOR_hor(cards);
	};
	int getValue(std::string card) const
	{
		if(card.size()!=2)
		{	
			PRINT_VECTOR_hor(cards);
		}
		assert(card.size()==2);
		char c=card[0];
		int r;
		if(   c>='0' 
				&& c<='9')
			r=c-48;
		else if(c=='T') r=10; // joker
		else if(c=='J') r=11;
		else if(c=='Q') r=12;
		else if(c=='K') r=13;
		else if(c=='A') r=14;
		else if(c=='a') r=10; // hex
		else if(c=='b') r=11;
		else if(c=='c') r=12;
		else if(c=='d') r=13;
		else if(c=='e') r=14;

		//PRINTVAR(r);
		return(r);
	};
	char getSuit(std::string card) const
	{
		if(card.size()!=2)
		{	
			PRINTVAR(card);
		}
		assert(card.size()==2);
		char c=card[1];
		//PRINTVAR(c);
		return c;
	}
	//int rank;
	//1Straight flush** 		| 	flushJack of clubs10 of clubs9 of clubs8 of clubs7 of clubs
	//2Four of a kind 		| 	5 of clubs5 of diamonds5 of hearts5 of spades2 of diamonds
	//3Full house 				| 	6 of spades6 of hearts6 of diamondsKing of clubsKing of hearts
	//4HFlush** 				| 	4HFlushJack of diamonds9 of diamonds8 of diamonds4 of diamonds3 of diamonds
	//5QueenStraight** 		| 	5QueenStraight10 of diamonds9 of spades8 of hearts7 of diamonds6 of clubs
	//6Three of a kind 		| 	5Queen of clubsQueen of spadesQueen of hearts9 of hearts2 of spades
	//7Two pair 				| 	Jack of heartsJack of spades3 of clubs3 of spades2 of hearts
	//8One pair 				| 	Jack10 of spades10 of hearts8 of spades7 of hearts4 of clubs
	//9High card 				| 	 

	bool theSame(PokerHand other) const
	{
		for(int i=0;i<5;i++)
		{
			if(cards[i]!=other.cards[i])
				return false;
		}
		return true;
	};
	bool theSameValue(PokerHand other) const
	{
		for(int i=0;i<5;i++)
		{
			if(getValue(cards[i])!=getValue(other.cards[i]))
				return false;
		}
		return true;
	};
	int getLargestPairValue() const
	{
		for(auto it=cards.end()-1;it!=cards.begin()+1;it--)
		{
			auto card1=*(it-1);
			auto card2=*it;
			if(getValue(card1)==getValue(card2))
				return getValue(card1);
		}
		return -1;
	};
	int getLargestPairValue(std::vector<std::string> cc) const
	{
		for(auto it=cc.end();it!=cc.begin()+1;it--)
		{
			auto card1=*(it-1);
			auto card2=*it;
			if(getValue(card1)==getValue(card2))
				return getValue(card1);
		}
		return -1;
	};
	int getLargestThreeValue() const
	{
		for(auto it=cards.end()-1;it!=cards.begin()+2;it--)
		{
			auto card0=*(it-2);
			auto card1=*(it-1);
			auto card2=*it;
			if(
					getValue(card0)==getValue(card1) &&
					getValue(card1)==getValue(card2)
			  )
				return getValue(card0);
		}
		return -1;
	};
	int getLargestFourValue() const
	{
		for(auto it=cards.end()-1;it!=cards.begin()+3;it--)
		{
			auto card0=*(it-3);
			auto card1=*(it-2);
			auto card2=*(it-1);
			auto card3=*it;

			if(
					getValue(card0)==getValue(card1) &&
					getValue(card1)==getValue(card2) &&
					getValue(card2)==getValue(card3)
			  )
				return getValue(card0);
		}
		return -1;
	};
	Result compare (int a,int b) const
	{
		if(a==b)
			return TIE;
		else
			return (a>b)?WIN:LOSS;
	};
	Result compare (std::string  stra,std::string  strb) const
	{
		int a=getValue(stra);
		int b=getValue(strb);
		return compare(a,b);
	};
	Result compareInRank1(PokerHand other) const
	{
		if(getValue(cards[4])<getValue(other.cards[4]))
			return Result::Loss;
		if(getValue(cards[4])==getValue(other.cards[4]))
			return Result::Tie;
		if(getValue(cards[4])>getValue(other.cards[4]))
			return Result::Win;
	};
	Result compareInRank2(PokerHand other) const
	{
		if(getLargestFourValue()<other.getLargestFourValue())
			return Result::Loss;
		else if(getLargestFourValue()>other.getLargestFourValue())
			return Result::Win;
		else 
			if(getLargestPairValue()<other.getLargestPairValue())
				return Result::Loss;
			else if(getLargestPairValue()>other.getLargestPairValue())
				return Result::Win;
			else 
				return Result::Tie;
	};
	Result compareInRank3(PokerHand other) const
	{
		if(theSameValue(other))
			return Result::Tie;
		if(getLargestThreeValue()==getLargestThreeValue())
			return (getLargestPairValue()>getLargestPairValue())?Result::Win:Result::Loss;
		else
			return (getLargestThreeValue()>getLargestThreeValue())?Result::Win:Result::Loss;
	};
	Result compareInRank4(PokerHand other) const
	{
		if(cards[4]==other.cards[4])
			if(cards[3]==other.cards[3])
				if(cards[2]==other.cards[2])
					if(cards[1]==other.cards[1])
						if(cards[0]==other.cards[0])
							return Result::Tie;
						else
							return (cards[0]>other.cards[0])?Result::Win:Result::Loss;
					else
						return (cards[1]>other.cards[1])?Result::Win:Result::Loss;
				else
					return (cards[2]>other.cards[2])?Result::Win:Result::Loss;
			else
				return (cards[3]>other.cards[3])?Result::Win:Result::Loss;
		else
			return (cards[4]>other.cards[4])?Result::Win:Result::Loss;
	};
	Result compareInRank5(PokerHand other) const
	{
		return compareInRank1(other);
	};
	Result compareInRank6(PokerHand other) const
	{
		if(theSameValue(other))
			return Result::Tie;
		if(getLargestThreeValue()==other.getLargestThreeValue())
			return (getLargestPairValue()>other.getLargestPairValue())?Result::Win:Result::Loss;
		else
			return (getLargestThreeValue()>other.getLargestThreeValue())?Result::Win:Result::Loss;
	};
	Result compareInRank7(PokerHand other) const
	{
		return TIE;
	};
	Result compareInRank8(PokerHand other) const
	{
		if(theSameValue(other))
			return Result::Tie;
		if(getLargestPairValue()==other.getLargestPairValue())
			if(compare(cards[4],other.cards[4])!=TIE)
				return compare(cards[4],other.cards[4]);
			else if(compare(cards[3],other.cards[3])!=TIE)
				return compare(cards[3],other.cards[3]);
			else if(compare(cards[2],other.cards[2])!=TIE)
				return compare(cards[2],other.cards[2]);
			else if(compare(cards[1],other.cards[1])!=TIE)
				return compare(cards[1],other.cards[1]);
			else if(compare(cards[0],other.cards[0])!=TIE)
				return compare(cards[0],other.cards[0]);
			else
				return (getLargestPairValue()>other.getLargestPairValue())?Result::Win:Result::Loss;
	};
	Result compareInRank9(PokerHand other) const
	{
		compare(cards[4],other.cards[4]);
	};

	bool isRank1() const
	{
		for(auto it=cards.begin()+1;it!=cards.end();it++)
		{
			auto card1=*(it-1);
			auto card2=*it;
			if(getSuit(card1)!=getSuit(card2))
				return false;
			if(getValue(card1)+1!=getValue(card2))
				return false;
		}
		return true;
	};
	bool isRank2() const
	{
		auto it=cards.begin();
		auto card0=*it;
		it++; auto card1=*it;
		it++; auto card2=*it;
		it++; auto card3=*it;
		it++; auto card4=*it;

		if(
				getValue(card0)==getValue(card1) &&
				getValue(card1)==getValue(card2) &&
				getValue(card2)==getValue(card3) 
		  )
			return true;
		if(
				getValue(card1)==getValue(card2) &&
				getValue(card2)==getValue(card3) &&
				getValue(card3)==getValue(card4) 
		  )
			return true;
		return false;
	};
	bool isRank3() const
	{
		auto it=cards.begin();
		auto card0=*it;
		it++; auto card1=*it;
		it++; auto card2=*it;
		it++; auto card3=*it;
		it++; auto card4=*it;

		if(
				(		getValue(card0)==getValue(card1) &&
						getValue(card1)==getValue(card2) 
				) &&
				getValue(card3)==getValue(card4) 
		  )
			return true;
		if(
				(		getValue(card2)==getValue(card3) &&
						getValue(card3)==getValue(card4) 
				) &&
				getValue(card0)==getValue(card1) 
		  )
			return true;
		return false;
	};
	bool isRank4() const
	{
		for(auto it=cards.begin()+1;it!=cards.end();it++)
		{
			auto card1=*(it-1);
			auto card2=*it;
			if(getSuit(card1)!=getSuit(card2))
				return false;
		}
		return true;
	};
	bool isRank5() const
	{
		for(auto it=cards.begin()+1;it!=cards.end();it++)
		{
			auto card1=*(it-1);
			auto card2=*it;
			if(getValue(card1)+1!=getValue(card2))
				return false;
		}
		return true;
	};
	bool isRank6() const
	{
		auto it=cards.begin();
		auto card0=*it;
		it++; auto card1=*it;
		it++; auto card2=*it;
		it++; auto card3=*it;
		it++; auto card4=*it;

		if(
				getValue(card0)==getValue(card1) &&
				getValue(card1)==getValue(card2) 

		  )
			return true;
		if(
				getValue(card2)==getValue(card3) &&
				getValue(card3)==getValue(card4) 

		  )
			return true;
		return false;
	};
	bool isRank7() const
	{
		auto it=cards.begin();
		auto card0=*it;
		it++; auto card1=*it;
		it++; auto card2=*it;
		it++; auto card3=*it;
		it++; auto card4=*it;

		if(
				getValue(card0)==getValue(card1) &&
				getValue(card2)==getValue(card3) 
		  ) return true;
		if(
				getValue(card0)==getValue(card1) &&
				getValue(card3)==getValue(card4) 
		  ) return true;
		if(
				getValue(card1)==getValue(card2) &&
				getValue(card3)==getValue(card4) 
		  ) return true;
		return false;
	};
	bool isRank8() const
	{
		std::vector<int>dashboard;
		for(auto it=cards.begin();it!=cards.end();it++)
		{
			auto card=*it;
			auto v=getValue(card);
			if(find(dashboard.begin(),dashboard.end(),v)==dashboard.end())
				dashboard.push_back(v);
		}
		return (dashboard.size()==4);
	};
	bool isRank9() const
	{
		std::vector<int>dashboard;
		for(auto it=cards.begin();it!=cards.end();it++)
		{
			auto card=*it;
			auto v=getValue(card);
			if(find(dashboard.begin(),dashboard.end(),v)==dashboard.end())
				dashboard.push_back(v);
		}
		return (dashboard.size()==5);
	};

	int getRank() const
	{
		int r;
		PRINT_DEBUG_INFO_PREFIX("getRank for:");
		for(auto s:cards)
		{
			//PRINTVAR(s);
		}
		if(isRank1()) r= 1;
		else if(isRank2()) r= 2;
		else if(isRank3()) r= 3;
		else if(isRank4()) r= 4;
		else if(isRank5()) r= 5;
		else if(isRank6()) r= 6;
		else if(isRank7()) r= 7;
		else if(isRank8()) r= 8;
		else if(isRank9()) r= 9;
		PRINTVAR(r);
		return r;
	};
};


Result compare (const PokerHand &player, const PokerHand &opponent) {
	std::cout<<"============================================="<<""<<std::endl;
	PRINTVAR(player.input );
	PRINTVAR(opponent.input );
	int r1=player.getRank();
	int r2=opponent.getRank();
	Result rv;
	if(r1!=r2)
		rv= (r1<r2)?WIN:LOSS;
	else if(player.theSame(opponent))
		rv= TIE;
	else if(r1==1)
		rv= player.compareInRank1(opponent );
	else if(r1==2)
		rv= player.compareInRank2(opponent );
	else if(r1==3)
		rv= player.compareInRank3(opponent );
	else if(r1==4)
		rv= player.compareInRank4(opponent );
	else if(r1==5)
		rv= player.compareInRank5(opponent );
	else if(r1==6)
		rv= player.compareInRank6(opponent );
	else if(r1==7)
		rv= player.compareInRank7(opponent );
	else if(r1==8)
		rv= player.compareInRank8(opponent );
	else if(r1==9)
		rv= player.compareInRank9(opponent );

	PRINT_DEBUG_INFO_PREFIX("rv");
	if(rv==WIN) 	PRINT_DEBUG_INFO_PREFIX("WIN");
	if(rv==LOSS) 	PRINT_DEBUG_INFO_PREFIX("LOSS");
	if(rv==TIE) 	PRINT_DEBUG_INFO_PREFIX("TIE");
	PRINTVAR(player.input );
	PRINTVAR(opponent.input );
	return rv;
}

int main ()
{

	char* s1="2H 3H 4H 5H 6H"; 
	char* s2="KS AS TS QS JS"; 
	s1="AS AH 2H AD AC"; 
	s2="JS JD JC JH 3D";
	s1="6S AD 7H 4S AS"; 
	s2="AH AC 5H 6H 7S";
	PokerHand p1(s1);
	PokerHand p2(s2);
#if 0
	//compare(p1,p2);

	PokerHand p3("2H 2H 4H 2H 2D");
	PRINTVAR(p1.isRank1());
	PRINTVAR(p2.isRank1());
	PRINTVAR(p3.isRank1());
	PRINTVAR(p3.isRank2());
#endif
	compare(p1,p2);
#if 0
	for(int i=0;i<1000;i++)
	{
		char c=i;
		PRINTVAR_hor(i);
		PRINTVAR(c);
	}
#endif
	return 0;
}
