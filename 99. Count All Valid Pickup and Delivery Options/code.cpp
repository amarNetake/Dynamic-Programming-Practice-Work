class Solution {
public:
    long int DeliveryPermutations(int n,int modulo)
    {
        long int itr=1;
        long int num=1;
        while(n>0)
        {
            num=(num*itr)%modulo;
            itr=itr+2;
            n--;
        }
        return num;
    }
    
    long int  pickupPermuations(int n,int modulo)
    {
        long int perm=1;
        while(n>0)
        {
            perm=(perm*n)%modulo;
            n--;
        }
        return perm;
    }
    
    int countOrders(int n) {
        int modulo=1e9+7;
        long int result=DeliveryPermutations(n,modulo);
        result=(result*pickupPermuations(n,modulo))%modulo;
        return result;
    }
};