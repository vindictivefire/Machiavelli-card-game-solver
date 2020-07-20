#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include <time.h>
#include "numeric"

// Samples:S1 H1 C1 D4 D5 D6 D7 S3 C3 D3 H3 H4 H5 H6 H7 S11 H11 C11 D12 D13 D1 H9 H10 H11 S2 H2 C2 D2 C7 C8 C9 C10 C11 C12 S5 H5 D5 D10 D12 D11 S7 S8 S9 S10 S11 S8 H8 C8 S13 H13 C13 S7 H7 D7 H6 C6 D6 S13 D13 H13
// S2 S3 S6 S6 S8 S10 S13 H3 H5 H11 C4 C7 D2 D5 D8 D11 S8 C4 S2 H10 D6 S3 S4 S5 S1 C13 C7 H6 H7 H8 H12 H2 D11 H10 C2 C11 H13 H1 C8 H4 S4 C12 D6 D7 D9 S13 C9 D1 D13 H2 H5 H4 C1 H9 C10 C13 S10 C10 D10 S12 H3 D3 C3 H8 C9 S12 C12 D12 H6 S7 H13 S9 S5 D10 C5 D5 C8 C11 S9 H9 D9
// H3 H4 H5 D3 D4 D5 H7 H8 H9 H2 H10 D6 S2 S6 S8 H1 H7 H10 C3 C13 D1 D5 D9 D12 D11 S10 S7 S11 C6 H12 S2 S4 H11 S8 C5 D3 S9 S7 C9 C10 C11 C7 S1 C5 S3 D11 C2 D7 C11 D8 D9 D10 C4 H2 S1 D12 S10 S11 H13 H8 D8 C4 H1 D13 D1 H3 D4 S12 S4 H11 C1 C10 D13 D2 H5 H6 H4 D7 S3 S5 C12 C13 wins at C10, but C1 takes really long
// D5 D6 D7 S4 H4 C4 C5 C6 C7 S2 C2 H2 S1 S6 S7 S9 S13 S13 H1 D1 H9 D9 H3 H5 H13 C4 C6 C12 C12 D7 D2 D3 D9 D11 C3 S7 H6 S6 H11 D8 D4 H6 H7 S5 D2 S2 H7 S10 S1 H1 D1 D3 D5 D6 S8 S9 C5 C10 D10 C3 S3 C1 C1 H8 H5 S3 H12 D4 S8 H9 S11 C8 H10 S4 S12 H12 D12 H11 D8 C9 S12 C9 C10 C11 H8 C13 C7 S5 S10 S11
// D5 D6 D7 S4 H4 C4 C5 C6 C7 S2 C2 H2 S1 S6 S7 S9 S13 S13 H1 D1 H9 D9 H3 H5 H13 C4 C6 C12 C12 D7 D2 D3 D9 D11 C3 S7 H6 S6 H11 D8 D4 H6 H7 S5 D2 S2 H7 S10 S1 H1 D1 D3 D5 D6 S8 S9 C5 C10 D10 C3 S3 C1 C1 H8 H5 S3 H12 D4 S8 H9 S11 C8 H10 S4 S12 H12 D12 H11 D8 C9 S12 C9 0.01s, not solved yet by others

int Check_triple(const std::vector<int>& cards, const int& card_specific); // checks if card is in a triple, quad, or none.
int Check_straight(const std::vector<int>& cards, const int& card_specific);  // Finds the number of straights a card can be in
int evaluator(const std::vector<int> cards);
std::vector<std::vector<int> > FindHands(const std::vector<int>& cards, const int& card_specific);
inline int numberofhands(const std::vector<int>& currentcards,const int& card_specific);


std::vector<std::vector<int>> results; // stores the winning combination




int main(int argc, char const *argv[]) {

	std::vector<int> cards;
	std::vector<std::string> foo(10000); // input numbers
	std::vector<std::string> visual;    // displayed cards
	std::vector <int> card_prev_unerased;
	std::vector<std::vector<int> > results2;
	std::cout << "\nEnter suit followed by number. S H C D for Spade heart club diamond, 1-13 for Ace-King. Type done to run computation. \n\nSample (You can copy paste this): H3 H4 H5 D3 D4 D5 H7 H8 H9 H2 H10 D6 S2 S6 S8 H1 H7 H10 C3 C13 D1 D5 D9 D12 D11 S10 S7 S11 C6 H12 S2 S4 H11 S8 C5 D3 S9 S7 C9 C10 C11 C7 S1 C5 S3 D11 C2 D7 C11 D8 D9 D10 C4 H2 S1 D12 S10 S11 H13 H8 D8 C4 H1 D13 D1 H3 D4 S12 S4 H11 C1 C10 D13 D2 H5 H6 H4 D7 S3 S5 C12 C13  " << '\n'; \

	// Getting Input, this is very clumsy
	int inp=0;
	int it =0;
	while(true) {
		while(foo[it-1] != "done") {
			cards = card_prev_unerased; // refreshing cards after each failure because the unique-combi cards were erased from previous results
			std::cin.clear();
			std::cin >> foo[it];
			inp=0;
			if (foo[it][0]=='H') {
				inp += 13;
			}
			else if (foo[it][0]=='C') {
				inp += 26;
			}
			else if(foo[it][0]=='D') {
				inp += 39;
			}
			if(foo[it][0]=='S' || foo[it][0]=='C' || foo[it][0]=='D' || foo[it][0]=='H')    {
				visual.push_back(foo[it]);
				inp += stoi(std::string(foo[it].begin()+1,foo[it].end()));
				cards.push_back(inp);
			}
			card_prev_unerased= cards;
			for (size_t i = 0; i < visual.size(); i++) {
				std::cout << visual[i] << " ";
			}
			std::cout << "" << '\n';
			it++;
		}

		std::sort(cards.begin(), cards.end());
		std::cout << "Number of cards:" << cards.size() <<"\n";
		int start = clock();
		// Reduce Hand
		bool trk = true;
		while (trk) {
			if(cards.empty()) { break; }
			for (size_t tempiter = 0; tempiter < cards.size(); tempiter++) { // tempiter loops over input
				//	std::cout << " check1 " << cards.size() << '\n';
				std::vector<std::vector<int> > uniquehand = FindHands(cards,cards[tempiter]);
				if(uniquehand.size()==1) {                                                                 // if there is a unique combination
					results2.push_back(uniquehand[0]);                                                 // storing combination into results
					for (size_t i = 0; i < uniquehand[0].size(); i++) {                                // i loops over unique combination to delete it
						cards.erase(std::lower_bound(cards.begin(),cards.end(),uniquehand[0][i])); // Deleting the combination from the hand,
						//											std::cout << " check4 " << cards.size() << '\n';
					}
					//					std::cout << " check2 " << cards.size() << '\n';
					trk = true;
					break;
				}
				else {
					trk = false; // break out of loop if irreducable hand
				}
			}

		}

		// Success
		if(evaluator(cards)==1) {
			int end = clock();
			std::cout << "it took " << end - start << "ticks, or " << ((float)end - start)/CLOCKS_PER_SEC << "seconds." << std::endl;
			std::cout << "Success!" << '\n';

			// Getting Results
			if(!results.empty()){
			for (size_t i = results.size()-1; i > 0; i--) {
				for (size_t j = 0; j < results[i-1].size(); j++) {
					results[i].erase(std::lower_bound(results[i].begin(),results[i].end(),results[i-1][j]));
				}
			}
		}

			results.insert(results.end(),results2.begin(),results2.end());
			for (size_t i = 0; i < results.size(); i++) {
				for (size_t j = 0; j < results[i].size(); j++) {
					if(results[i][j]<14) {
						std::cout << "S" << results[i][j];
					}
					else if (results[i][j]<27) {
						std::cout << "H" << results[i][j]-13;
					}
					else if (results[i][j]<40) {
						std::cout << "C" << results[i][j]-26;
					}
					else {
						std::cout << "D" << results[i][j]-39;
					}
					if(j!=results[i].size()-1){std::cout << ",";}
				}
				std::cout << '\n';
			}
			std::cin.clear();
			std::cin>>inp;
			return 0;
		}

		// Failure
		else {

			int end = clock();
			std::cout << "it took " << end - start << "ticks, or " << ((float)end - start)/CLOCKS_PER_SEC << "seconds." << std::endl;
			std::cout << "Fail" << '\n';
			it++;
			results2.clear();
		} // fail
	}

	return 0;
}



int evaluator(std::vector<int> cards){

 if(cards.empty()) {return 1;}


	// if there is a unique combination

	// std::cout << " Erasing unique hands " << '\n';
	std::vector<int> oldcards = cards;
	std::vector<std::vector<int> > currenthand;
	bool loop = true;
	int minnum=100;
	int idx   =0;
	while(loop) {
		loop   = false;
		minnum = 100;

		for (size_t i = 0; i < cards.size(); i++) {

			unsigned int num = numberofhands(cards,cards[i]);
			switch (num) {

			case 0: { return 0;}

			case 1: {

				currenthand = FindHands(cards,cards[i]);
				if(currenthand.size()!=num) {
					std::cout << num << '\n';
					std::cout << currenthand.size() << '\n';
					for (int i = 0; i < cards.size(); i++) {  // If there is a card with only one possible hand it can be it, delete that hand from the original cards
						std::cout << cards[i] << ",";
					}

				}
				for (size_t j = 0; j < currenthand[0].size(); j++) {


					cards.erase(std::lower_bound(cards.begin(),cards.end(),currenthand[0][j]));   // Deleting the combination from the hand,
				}

				if(cards.empty()) {                 return 1;                               }
				loop = true;

				break;

			}

			default: {
				if(num<minnum) {minnum=num; idx = i;}
			}
			}
		}

	}

	currenthand = FindHands(cards,cards[idx]);
	std::vector<int> cardtemp;
	for (size_t i = 0; i < currenthand.size(); i++) {
		cardtemp = cards;
		for (size_t j = 0; j < currenthand[i].size(); j++) {
			cardtemp.erase(std::lower_bound(cardtemp.begin(),cardtemp.end(),currenthand[i][j]));   // hand[i] represents the combination, I loop over this combination to delete from cards these values.
		}
		if(evaluator(cardtemp)==1) {
			results.push_back(cards);
			if(oldcards.size()!=cards.size()) {
				results.push_back(oldcards);
			}
			return 1;
		}
		// if not true, go back and iterate through the other possible hands of the last junctions in a tree search algorithm

	}
	return 0;
}
int Check_triple(const std::vector<int>& currentcards,const int& card_specific){  // Returns 0 if triple, 1 if quad, negative if nothing

	if( card_specific < 14 ) {
		// searching for cards of the same number
		return std::binary_search(currentcards.begin(),currentcards.end(),card_specific+13) + std::binary_search(currentcards.begin(),currentcards.end(),card_specific+26) + std::binary_search(currentcards.begin(),currentcards.end(),card_specific+39) -2;
	}
	else if(card_specific < 27 ) {
		// searching for cards of the same number
		return std::binary_search(currentcards.begin(),currentcards.end(),card_specific-13)+std::binary_search(currentcards.begin(),currentcards.end(),card_specific+13)+std::binary_search(currentcards.begin(),currentcards.end(),card_specific+26) -2;
	}
	else if (card_specific < 40) {

		return std::binary_search(currentcards.begin(),currentcards.end(),card_specific-26)+std::binary_search(currentcards.begin(),currentcards.end(),card_specific-13)+std::binary_search(currentcards.begin(),currentcards.end(),card_specific+13) -2;

	}
	else {
		return std::binary_search(currentcards.begin(),currentcards.end(),card_specific-39)+std::binary_search(currentcards.begin(),currentcards.end(),card_specific-26)+std::binary_search(currentcards.begin(),currentcards.end(),card_specific-13) -2;

	}
}
int Check_straight( const std::vector<int>& currentcards,const int& card_specific){
	int rem = card_specific % 13;
	int pos_begin, pos_end;
	if( rem == 1) {

		auto Kpos = std::find(currentcards.begin(),currentcards.end(),card_specific+12);
		// Searching downwards

		if(currentcards.end()-Kpos>0 && *Kpos == card_specific+12 ) {         // found
			pos_begin = -1;
			while (true) {
				if (Kpos-currentcards.begin()>0 && *(Kpos-1) == card_specific + 13 + pos_begin -1  && pos_begin!=-12) {
					pos_begin--;
					Kpos = Kpos-1;
				}
				else if (Kpos-currentcards.begin()>1 && *(Kpos-2) == card_specific + 13 + pos_begin -1 && pos_begin!=-12) {
					pos_begin--;
					Kpos = Kpos-2;
				}
				else {
					break;
				}
			}
		}


		else { pos_begin = 0;}
		// Searching upwards
		auto pos1 = std::lower_bound(currentcards.begin(),currentcards.end(),card_specific);
		pos_end = 0;                             // FOR SOME REASON I DECIDE TO USE 0 AS 1's POSITION
		while (true) {

			if (currentcards.end()-1-pos1>0 && *(pos1+1) == card_specific + pos_end + 1 && pos_end!=11) {
				pos_end++;
				pos1 = pos1+1;
			}
			else if (currentcards.end()-1-pos1>1 && *(pos1+2) == card_specific + pos_end + 1 && pos_end!=11) {
				pos_end++;
				pos1=pos1+2;
			}
			else {
				break;
			}


		}
		// std::cout << pos_begin << '\n';
		// std::cout << pos_end << '\n';
		return (0-pos_begin>=2) * (-1-pos_begin) + (pos_end>=2) * (pos_end-1);
	}

	else{
		auto npos  = std::lower_bound(currentcards.begin(),currentcards.end(),card_specific);
		auto npos2 = npos;
		// Searching downwards
		if(rem==0) {rem=13;}
		pos_begin = rem;
		pos_end   = rem;
		while(true) {
			// std::cout << pos_begin << '\n';
			if(npos-currentcards.begin()>0) {
				if(*(npos-1) == card_specific+pos_begin-rem-1 && pos_begin!= 1) {
					pos_begin--;
					npos = npos-1;

				}

				else if (npos-currentcards.begin()>1 && *(npos-2) == card_specific + pos_begin - rem - 1 && pos_begin!=1) {
					// std::cout << pos_begin << '\n';
					pos_begin--;
					npos--;
					npos--;
				}
				else {break;}
			}
			else {break;}
		}
		// std::cout << pos_begin << '\n';
		// Searching upwards
		while(true) {
			if(currentcards.end()-1-npos2>0) {
				if(*(npos2+1) == card_specific+pos_end-rem+1 && pos_end!= 13) {
					pos_end++;
					npos2 = npos2+1;
				}
				else if (currentcards.end()-1-npos2>1 && *(npos2+2) == card_specific + pos_end- rem +1 && pos_end!=13) {
					pos_end++;
					npos2=npos2+2;
				}
				else {break;}
			}
			else {break;}
		}
		if(pos_end==13) {
			if(std::binary_search(currentcards.begin(),currentcards.end(),card_specific-rem+1)) { pos_end = 14;}
		}
	}

	if(rem!=pos_begin && rem!= pos_end) {return (pos_end-rem+1)*(rem-pos_begin+1)-3;}
	else return (rem-pos_begin+1)*(pos_end-rem+1)-2;
}
inline int numberofhands(const std::vector<int>& currentcards,const int& card_specific){
	int out   =0;
	int temp  = Check_triple(currentcards,card_specific);
	int temp2 = Check_straight(currentcards,card_specific);
	if (temp==0) {out+=1;}
	else if(temp==1) {out+=4;}
	if(temp2>0) {out+=temp2;}
	return out;
}
std::vector<std::vector<int> > FindHands(const std::vector<int>& currentcards,const int& card_specific){
	std::vector<std::vector<int> > out;
	int tempcard1, tempcard2, tempcard3;
	bool temp1, temp2, temp3;
	if( card_specific < 14 ) {
		tempcard1 = card_specific+13;
		tempcard2 = card_specific+26;
		tempcard3 = card_specific+39;
		temp1     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard1);
		temp2     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard2);
		temp3     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard3);
		// searching for cards of the same number
	}
	else if (card_specific < 27) {
		tempcard1 = card_specific-13;
		tempcard2 = card_specific+13;
		tempcard3 = card_specific+26;
		temp1     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard1);
		temp2     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard2);
		temp3     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard3);
	}
	else if (card_specific < 40) {
		tempcard1 = card_specific-26;
		tempcard2 = card_specific-13;
		tempcard3 = card_specific+13;
		temp1     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard1);
		temp2     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard2);
		temp3     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard3);
	}
	else {
		{
			tempcard1 = card_specific-39;
			tempcard2 = card_specific-26;
			tempcard3 = card_specific-13;
			temp1     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard1);
			temp2     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard2);
			temp3     = std::binary_search(currentcards.begin(),currentcards.end(),tempcard3);
		}
	}
	if(temp1 + temp2 + temp3 < 2)
	{}
	else if (temp1 + temp2 + temp3 >2) {
		out = {{card_specific,tempcard1,tempcard2},{card_specific,tempcard1,tempcard3},{card_specific,tempcard2,tempcard3},{card_specific,tempcard1,tempcard2,tempcard3}};
	}
	else if (!temp1) {
		out = {{card_specific,tempcard2,tempcard3}};
	}

	else if (!temp2) {
		out = {{card_specific, tempcard1, tempcard3}};
	}
	else {
		out = {{card_specific, tempcard1, tempcard2}};
	}
	// Finding straights
	int rem = card_specific % 13;

	if( rem == 1) {
		int pos_begin = -1;
		int pos_end   = 0;
    auto Kpos = std::find(currentcards.begin(),currentcards.end(),card_specific+12);
		// Searching downwards

		if(currentcards.end()-Kpos>0 && *Kpos == card_specific+12 ) {         // found
			while (true) {
				if (Kpos-currentcards.begin()>0 && *(Kpos-1) == card_specific + 13 + pos_begin -1  && pos_begin!=-12) {
					pos_begin--;
					Kpos = Kpos-1;
				}
				else if (Kpos-currentcards.begin()>1 && *(Kpos-2) == card_specific + 13 + pos_begin -1 && pos_begin!=-12) {
					pos_begin--;
					Kpos = Kpos-2;
				}
				else {
					break;
				}
			}
		}


		else { pos_begin = 0;}
		// Searching upwards
		auto pos1 = std::lower_bound(currentcards.begin(),currentcards.end(),card_specific);
		while (true) {

			if (currentcards.end()-1-pos1>0 && *(pos1+1) == card_specific + pos_end + 1 && pos_end!=11) {
				pos_end++;
				pos1 = pos1+1;
			}
			else if (currentcards.end()-1-pos1>1 && *(pos1+2) == card_specific + pos_end + 1 && pos_end!=11) {
				pos_end++;
				pos1=pos1+2;
			}
			else {
				break;
			}


		}
    pos_end++;
		if(pos_end >2 ) {
			for (size_t i = 3; i <= pos_end; i++) {
				std::vector<int> v(i);
				std::iota(v.begin(), v.end(), card_specific);
				out.push_back(v);
			}
		}
    pos_begin+=14;
		if (pos_begin < 13 ) {
			for (size_t i = 12; i > pos_begin-1; i--) {
				int n = 12+card_specific;
				std::vector<int> x(14-i);
				std::generate(x.begin(), x.end(), [&n] {
					return n--;
				});

				x.push_back(1);
				out.push_back(x);
			}
		}
	}

	else {
    auto npos  = std::lower_bound(currentcards.begin(),currentcards.end(),card_specific);
		auto npos2 = npos;
		// Searching downwards
		if(rem==0) {rem=13;}
		int pos_begin = rem;
		int pos_end   = rem;
		while(true) {
			// std::cout << pos_begin << '\n';
			if(npos-currentcards.begin()>0) {
				if(*(npos-1) == card_specific+pos_begin-rem-1 && pos_begin!= 1) {
					pos_begin--;
					npos = npos-1;

				}

				else if (npos-currentcards.begin()>1 && *(npos-2) == card_specific + pos_begin - rem - 1 && pos_begin!=1) {
					// std::cout << pos_begin << '\n';
					pos_begin--;
					npos--;
					npos--;
				}
				else {break;}
			}
			else {break;}
		}
		// std::cout << pos_begin << '\n';
		// Searching upwards
		while(true) {
			if(currentcards.end()-1-npos2>0) {
				if(*(npos2+1) == card_specific+pos_end-rem+1 && pos_end!= 13) {
					pos_end++;
					npos2 = npos2+1;
				}
				else if (currentcards.end()-1-npos2>1 && *(npos2+2) == card_specific + pos_end- rem +1 && pos_end!=13) {
					pos_end++;
					npos2=npos2+2;
				}
				else {break;}
			}
			else {break;}
		}
		if(pos_end==13) {
			if(std::binary_search(currentcards.begin(),currentcards.end(),card_specific-rem+1)) { pos_end = 14;}
		}
//	std::cout << "pos_begin is" << pos_begin <<'\n';
//	std::cout << "pos_end is " << pos_end << '\n';
	if(pos_end-pos_begin>1) {

		std::vector<int> x(pos_end-pos_begin+1);
		std::iota(x.begin(), x.end(), pos_begin+card_specific-rem);
		for (std::vector<int>::iterator i = x.begin(); i <= x.begin()+rem-pos_begin; i++) {
			for (std::vector<int>::iterator j = x.begin()+rem-pos_begin; j < x.end(); j++) {
				if(j-i>1) {
					std::vector<int> tempvec(i,j+1);         // +1 because the end of subvector is deleted
					if((*j)%13==1) {
						*(tempvec.end()-1)=card_specific-rem+1;
					}
					if(j-i!=13) {

						out.push_back(tempvec);
					}
				}
			}
		}

	}
}
	return out;
}
