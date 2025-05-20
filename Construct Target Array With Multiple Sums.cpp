class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        //first we require the max heap to keep the track of the heighest element
        priority_queue<int>p(target.begin(),target.end());

        long long sum=0;
        for(int i=0;i<target.size();i++)
        {
            sum+=(long long)target[i];
        }

        //sum=remSum+maxElement
        //remSum=sum-maxElement
        while(p.top()!=1)
        {
            int maxi=p.top();
            p.pop();

            long long remSum=sum-(long long)maxi;
            if(remSum<=0 || maxi-remSum<=0)
            {
                return 0;
            }

            //int Element=maxi-remSum;
            int Element=maxi%remSum;

            if(!Element)
            {
                if(remSum==1)
                {
                    return 1;
                }

                else 
                return 0;
            }
            
            p.push(Element);
            //we have to also update the sum
            //sum=remSum+maxElement
            //sum=remSum+(maxElement-remSum)
            //sum=remSum+(maxElement%remSum)
            //sum=remSum+Elemnet
            sum=remSum+Element;
        }

        return 1;
    }
};
