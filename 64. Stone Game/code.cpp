// stupid question:
/*
	if we are given with the total stones=odd which implies one of them will definately win.
	Now we are also given total number of piles=even
	Now let piles be  [a,b,c,d,e,f]
	Now 
	1. we will pick either just even position items if b+d+f > a+c+e
	2. We will pick just the odd position items if a+c+e > b+d+f
	3. a+c+e=b+d+f is not possible as number of stones are odd
	4. Now let us assume a+c+e > b+c+f then we will pick 'a' then the opponent will only be left with items at even positions that is b or f.
	then he will pick any of b or f(lets say he picked f). Now we will pick the odd position item that got exposed now that is e . Now again
	he is exposed with even positioned items that is b and d. Now he will pick any one of them(Lets say he picked b). Now we will pick the 
	item that was at odd position and got exposed. So we will pick c. Now he is left with only one item d. So he will pick d.
	Similarly if b+d+f > a+c+e then we would have started to pick the even position item.
	So We can always win if we are going to play the first chance as we have the control to make the opponent exposed to the items that are
	not desired by us. So we will win always.
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};