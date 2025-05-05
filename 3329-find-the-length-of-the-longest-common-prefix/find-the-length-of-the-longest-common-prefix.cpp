class Solution {
public:

    struct trieNode{
        trieNode * children[10]; //0 to 10 , only yehi numbers possible hai, toh 10 nodes max each node will have.
        //bool endOfWord ; -> not needed
        
    };

    trieNode * getNode(){
        trieNode *root = new trieNode();
        for(int i=0;i<10;i++) root->children[i]=NULL;

        return root;
    }


    void insert(trieNode *root,int num){
        trieNode * crawler = root;
        string num_str = to_string(num);

        for(auto ch : num_str){
            int ind = ch-'0';

            if(!crawler->children[ind])
                crawler->children[ind] = getNode();
            
             crawler = crawler->children[ind];
            
               
        }
    }


    int search(trieNode * root, int num){
         trieNode * crawler = root;
        string num_str = to_string(num);

        int len = 0;

        for(auto ch : num_str){
            int ind = ch-'0';

            if(crawler->children[ind]){
                len++;
                crawler = crawler->children[ind];
            }
            else break;   
        }
        return len;
    }




    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode * root = getNode();
        
        for(auto x: arr1) insert(root, x);

        int len =0;

        for(auto x: arr2){
            len = max(len, search(root,x));
        }

        return len;
    }
};