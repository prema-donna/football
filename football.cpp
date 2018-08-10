#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std;

class Offense{
	private:
		vector<pair<string,double>> categories;
	public:
		void add_offense(string category, double value){
			string cat = category;
			double val = value;
			for (int i= 0; i<categories.size(); i++){
				if (cat == categories[i].first || cat == "FL" && categories[i].first == "FUM" || cat == "FUM" && categories[i].first == "FL" || cat == "PYDS" && 
				    categories[i].first == "PASS" || cat == "PASS" && categories[i].first == "PYDS" || cat == "TD" && categories[i].first == "TDS" || cat == "TDS" &&
					categories[i].first == "TD" || cat == "INT" && categories[i].first == "INTS" || cat == "INTS" && categories[i].first == "INT" || cat == "TWO" &&
					categories[i].first == "2PT" || cat == "2PT" && categories[i].first == "TWO" || cat == "PTDS" && categories[i].first == "PTD" || cat == "PTD" &&
					categories[i].first == "PTDS"){
						cout<< "You've already entered that category!\n";
						return;
				}
			}
			if(cat == "PYDS" || cat == "PASS" || cat == "RUSH" || cat == "RECY" || cat == "TD" || cat == "TDS" || cat == "TWO" || cat == "2PT" || cat == "PTD" || 
			   cat == "PTDS" || cat == "INT" || cat == "INTS" || cat == "FUM" || cat == "FL" || cat == "REC"){
				categories.push_back(make_pair(cat,val));
			}
			else if(cat == "RYDS" || cat== "YDS"){
				cout<< "Please enter RUSH or RECY for rushing yards or receiving yards\n"; 
			}
			else if(cat == "RTD" || cat == "RTDS"){
				cout<< "Please enter TD or TDS as a catch-all term for touchdowns\n";
			}
			else{
				cout<<"Invalid category!\n";
			}
		}
		void prompt(){
			cout<<"Add a valid non-K/DEF football category (4 char limit, UPPERCASE), and its point value. Type Q 0 when finished\n";
			cout<<"Example: PASS 0.04\n"; 
			while(1){
				string cat;
				double cat_value;
				cout<<"Add a valid non-K/DEF category (4 char limit, UPPERCASE), and its point value. Type Q 0 when finished\n";
				cin>>cat;
				cin>>cat_value;
				if (cat == "Q" && cat_value == 0) break;
				else if(cat == "Q" && cat_value != 0){
					cout<<"Invalid quit command! Type Q 0\n";
				}
				else if (cat.length() <= 4){
					add_offense(cat,cat_value);
				}
				else{
					cout<<"Too many letters!\n";
				}
			}
		}
		vector<pair<string,double>> get_cats(){
			return categories;
		}
		void print_all_categories(){
			vector<pair<string,double>> cats = get_cats();
			int count = 0;
			cout<<"                    ";
			for(int i= 0; i< cats.size(); i++){
				if(cats[i].first == "PYDS" || cats[i].first == "PASS"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "PTD"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
				if(cats[i].first == "PTDS"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "INT"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
				if(cats[i].first == "INTS"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "RUSH"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "REC"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "RECY"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "TD"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"   "<<cats[i].first;
				}
				if(cats[i].first == "TDS"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "2PT" || cats[i].first == "TWO"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "FUM"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
				if(cats[i].first == "FL"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"   "<<cats[i].first;
				}
			}
			cout<<"\n";
		}
};

class Defense{
	private:
		vector<pair<string,double>> categories;
	public:
		void add_defense(string category,double value){
			string cat = category;
			double val = value;
			for (int i= 0; i<categories.size(); i++){
				if (cat == categories[i].first || cat == "FUM" && categories[i].first == "FR" || cat == "FR" && categories[i].first == "FUM" || cat == "SFTY" && 
				    categories[i].first == "SAFE" || cat == "SAFE" && categories[i].first == "SFTY" || cat == "S" && categories[i].first == "SAFE" || cat == "SAFE" &&
					categories[i].first == "S" || cat == "SFTY" && categories[i].first == "S" || cat == "S" && categories[i].first == "SFTY" || cat == "INT" &&
					categories[i].first == "INTS" || cat == "INTS" && categories[i].first == "INT" || cat == "RTD" && categories[i].first == "RTDS" || cat == "TDS" &&
					categories[i].first == "TD" || cat == "TD" && categories[i].first == "TDS" || cat == "RTDS" && categories[i].first == "RTD"){
						cout<< "You've already entered that category!\n";
						return;
				}
			}
			if(cat == "SACK" || cat == "INT" || cat == "INTS" || cat == "FR" || cat == "FUM" || cat == "TD" || cat == "TDS" || cat == "SAFE" || cat == "SFTY" || 
			   cat == "S" || cat == "BLK" || cat == "RTD" || cat == "RTDS" || cat == "PA" || cat == "XPR"){ 
				categories.push_back(make_pair(cat,val));
			}
			else {
				cout<<"Invalid category!\n";
			}
		}
		void prompt(){
			cout<<"Add a valid DEF/ST stat (4 letters max, UPPERCASE), and its point value. Type Q 0 when finished\n";
			cout<<"Example (return touchdown(s)): RTD 6\n"; 
			cout<<"For points allowed (PA), enter 0 as a point value. The program will ROUGHLY estimate this value\n"; 
			while(1){
				string cat;
				double cat_value;
				cout<<"Add a valid DEF/ST stat (4 letters max, UPPERCASE), type Q 0 when finished\n";
				cin>>cat;
				cin>>cat_value;
				if (cat == "Q" && cat_value == 0) break;
				else if(cat == "Q" && cat_value != 0){
					cout<<"Invalid quit command! Type Q 0\n";
				}
				else if (cat == "PA" && cat_value != 0){
					cout<<"Points allowed (PA) must have 0 as its point value\n";
				}
				else if (cat.length() <= 4){
					add_defense(cat,cat_value);
				}
				else{
					cout<<"Too many letters!\n";
				}
			}
		}
		vector<pair<string,double>> get_cats(){
			return categories;
		}
		void print_all_categories(){
			vector<pair<string,double>> cats = get_cats();
			int count = 0;
			cout<<"                    ";
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "SACK"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i< cats.size(); i++){
				if(cats[i].first == "INT"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
				if(cats[i].first == "INTS"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "FUM"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
				if(cats[i].first == "FR"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"   "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "TD"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"   "<<cats[i].first;
				}
				if(cats[i].first == "TDS"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "S"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"    "<<cats[i].first;
				}
				if(cats[i].first == "SFTY"||cats[i].first == "SAFE"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "BLK"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "RTD"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
				if(cats[i].first == "RTDS"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "PA"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"   "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "XPR"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
			}
			cout<<"\n";
		}
};

class Kicker{
	private:
		vector<pair<string,double>> categories;
	public:
		void add_kicker(string category,double value){
			string cat = category;
			double val = value;
			for (int i= 0; i<categories.size(); i++){
				if (cat == categories[i].first || cat == "50+" && categories[i].first == "FG50" || cat == "FG50" && categories[i].first == "50+"){
						cout<< "You've already entered that category!\n";
						return;
				}
			}
			if(cat == "FG19" || cat == "FG29" || cat == "FG39" || cat == "FG49" || cat == "FG50" || cat == "50+" || cat == "PAT"){ 
				categories.push_back(make_pair(cat,val));
			}
			else {
				cout<<"Invalid category!\n";
			}
		}
		void prompt(){
			cout<<"Add a kicking stat (4 letters max, UPPERCASE), and its point value. Type Q 0 when finished\n";
			cout<<"Example (0 to 19 yard FG): FG19 3\n";
			cout<<"For a FG range, take the largest possible number for the range as seen above\n";
			while(1){
				string cat;
				double cat_value;
				cout<<"Add a valid kicking stat (4 letters max, UPPERCASE), type Q 0 when finished\n";
				cin>>cat;
				cin>>cat_value;
				if (cat == "Q" && cat_value == 0) break;
				else if(cat == "Q" && cat_value != 0){
					cout<<"Invalid quit command! Type Q 0\n";
				}
				else if (cat.length() <= 4){
					add_kicker(cat,cat_value);
				}
				else{
					cout<<"Too many letters!\n";
				}
			}
		}
		vector<pair<string,double>> get_cats(){
			return categories;
		}
		void print_all_categories(){
			vector<pair<string,double>> cats = get_cats();
			int count = 0;
			cout<<"                    ";
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "FG19"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i< cats.size(); i++){
				if(cats[i].first == "FG29"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "FG39"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "FG49"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "FG50"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<" "<<cats[i].first;
				}
				if(cats[i].first == "50+"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "PAT"){
					categories[count].first = cats[i].first;
					categories[count].second = cats[i].second;
					++count;
					cout<<"  "<<cats[i].first;
				}
			}
			cout<<"\n";
		}
};

class Player:Offense,Defense,Kicker{
	private:
		string name;
		Offense o;
		Defense d;
		Kicker k;
		vector<pair<string,double>> cats;
		double stat_value;
		vector<int> statline;
	public:
		Player(string player, Offense a){
			name = player;
			o = a;
		}		
		Player(string player, Defense b){
			name = player;
			d = b;
		}
		Player(string player, Kicker c){
			name = player;
			k = c;
		}
		void player_prompt(bool is_offense, bool is_kicker){
			if (is_kicker == true){
				cats = k.get_cats();
			}
			else if(is_offense == false && is_kicker == false){
				cats = d.get_cats();
			}
			else if(is_offense == true && is_kicker == false){
				cats = o.get_cats();
			}
			for(int i= 0; i<cats.size(); i++){
				if(cats[i].first == "SACK"){
					cout<<"Enter "<<name<<"'s value for "<<cats[i].first<<", to the nearest integer\n";
				}
				else{
					cout<<"Enter "<<name<<"'s value for "<<cats[i].first<<"\n";
				}
				cin>>stat_value;
				statline.push_back(stat_value);
			}
			cout<<"\n";
		}
		vector<int> get_statline(){
			return statline;
		}
		void print_player_info(bool is_offense, bool is_kicker){
			if(is_kicker == true){
				k.print_all_categories();
			}
			else if(is_offense == false && is_kicker == false){
				d.print_all_categories();
			}
			else if(is_offense == true && is_kicker == false){
				o.print_all_categories();
			}
			cout<<name;
			int space_length= 20- name.length();
			while(space_length >0){
				cout<<" ";
				--space_length;
			}
			for(int i= 0; i<statline.size(); i++){
				if (statline[i]/10 == 0){
					cout<<"    "<<statline[i];  
				}
				else if(statline[i]/100 == 0){
					cout<<"   "<<statline[i];
				}
				else if(statline[i]/1000 == 0){
					cout<<"  "<<statline[i];
				}
				else if(statline[i]/10000 == 0){
					cout<<" "<<statline[i];
				}
			}
			cout<<"\n";
		}
};

double offense_total(Player player,Offense o){
	vector<pair<string,double>> cats = o.get_cats();
	vector<int> statline = player.get_statline();
	double value = 0;
	for(int i= 0; i<cats.size(); i++){
		value += (cats[i].second*statline[i]);
	}
	return value;
}

double defense_total(Player player,Defense d){ 
	vector<pair<string,double>> cats = d.get_cats();
	vector<int> statline = player.get_statline();
	double value = 0;
	for(int i= 0; i<cats.size(); i++){
		if(cats[i].first == "PA"){
			if(statline[i] == 0){
				value += 10;
			}
			if(statline[i] > 0 && statline[i] <= 6){
				value += 7;
			}
			if(statline[i] >= 7 && statline[i] <= 13){
				value += 4;
			}
			if(statline[i] >= 14 && statline[i] <= 20){
				value += 1;
			}
			if(statline[i] >= 28 && statline[i] <= 34){
				value -= 1;
			}
			if(statline[i] >= 35 && statline[i] <= 73){
				value -= 4;
			}
			if(statline[i] > 73){
				double average = statline[i]/16;
				if(statline[i] == 0){
				value += 10;
			}
			if(average > 0 && average <= 6){
				value += (16*7);
			}
			if(average >= 7 && average <= 13){
				value += (16*4);
			}
			if(average >= 14 && average <= 20){
				value += (16*1);
			}
			if(average >= 28 && average <= 34){
				value -= (16*1);
			}
			if(average >= 35){
				value -= (16*4);
			}
			}
		}
		else{
			value += (cats[i].second*statline[i]);
		}
	}
	return value;
}

double kicker_total(Player player,Kicker k){ 
	vector<pair<string,double>> cats = k.get_cats();
	vector<int> statline = player.get_statline();
	double value = 0;
	for(int i= 0; i<cats.size(); i++){
		value += (cats[i].second*statline[i]);
	}
	return value;
}

int main(){
	Offense o;
	o.prompt();
	o.print_all_categories();
	
	Defense d;
	d.prompt();
	d.print_all_categories();
	
	Kicker k;
	k.prompt();
	k.print_all_categories();
	
	string brady = "TomBrady2007";
	Player tom_brady(brady, o);
	tom_brady.player_prompt(true,false);
	tom_brady.print_player_info(true,false);
	cout<<brady<<"'s total fantasy points: "<<offense_total(tom_brady,o)<<"\n";
	
	string lynch = "MarshawnLynch2012";
	Player marshawn_lynch(lynch, o);
	marshawn_lynch.player_prompt(true,false);
	marshawn_lynch.print_player_info(true,false);
	cout<<lynch<<"'s total fantasy points: "<<offense_total(marshawn_lynch,o)<<"\n";
	
	string gronk = "RobGronkowski2011";
	Player rob_gronkowski(gronk, o);
	rob_gronkowski.player_prompt(true,false);
	rob_gronkowski.print_player_info(true,false);
	cout<<gronk<<"'s total fantasy points: "<<offense_total(rob_gronkowski,o)<<"\n";
	
	string bears85 = "ChicagoBears1985";
	Player chicago_bears_85(bears85, d);
	chicago_bears_85.player_prompt(false,false);
	chicago_bears_85.print_player_info(false,false);
	cout<<bears85<<"'s ESTIMATED total fantasy points: "<<defense_total(chicago_bears_85,d)<<"\n";
	
	string akers = "DavidAkers2011";
	Player david_akers(akers, k);
	david_akers.player_prompt(false,true);
	david_akers.print_player_info(false,true);
	cout<<akers<<"'s total fantasy points: "<<kicker_total(david_akers,k)<<"\n";
	
	return 0;
}