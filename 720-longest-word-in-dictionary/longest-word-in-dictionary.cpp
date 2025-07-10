class Solution {
public:

    class Trie{

        public : 

        struct trieNode{
            trieNode * children[26];
            bool isEndOfWord ; 
        };

        trieNode * getNode(){
            trieNode * newNode = new trieNode();
            newNode->isEndOfWord = false; 
            for(int i=0;i<26;i++) newNode->children[i]= NULL;

            return newNode; 
         }

        trieNode *root;
        string longestWord;
        Trie(){
            root= getNode();
            longestWord = "";
        }

        void insert(string word){
            trieNode * crawler = root; 

            for(int i=0;i<word.size();i++){
                int ind = word[i]-'a';
                if(!crawler->children[ind]) crawler->children[ind]= getNode();

                crawler = crawler->children[ind];
            }
        crawler->isEndOfWord = true;
        }
    
        void dfs(trieNode * node, string currWord){

            if(!node) return ; 

            if(node!=root && !node->isEndOfWord) return;

            if(currWord.size()>longestWord.size() || 
            (currWord.size()==longestWord.size()&& currWord<longestWord))
                        longestWord = currWord; 

            
            for(int i=0;i<26;i++){
                if(node->children[i]){
                    char ch = 'a'+i;
                    dfs(node->children[i],currWord+ch);
                }
                
            }

        }

        string getLongestWordWithAllPrefix(){
            dfs(root,"");
            return longestWord; 
        }

    };

    string longestWord(vector<string>& words) {
        
        Trie obj; 

        for(auto x: words) obj.insert(x);

        string ans = obj.getLongestWordWithAllPrefix();
        return ans;
    }
};