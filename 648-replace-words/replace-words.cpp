class Solution {
public:

struct trieNode{
            trieNode *children[26];
            bool endOfWord;
        };

        trieNode * getNode(){
            trieNode * root = new trieNode();
            root->endOfWord= false;

            for(int i=0;i<26;i++){
                root->children[i]=NULL;
            }
            return root;
        }


        void insert(string word, trieNode *root){
            trieNode * crawler =  root;

            for(int i=0;i<word.size();i++){
                int ind = word[i]-'a';
                if(!crawler->children[ind]) crawler->children[ind] = getNode();
                
                crawler = crawler->children[ind];
                
                }

                crawler->endOfWord = true;
        }

        string search(string word, trieNode *root){
            trieNode * crawler = root;

            for(int i=0;i<word.size();i++){
                int ind = word[i]-'a';
                if(!crawler->children[ind]) return word; //no prefix was found in trie

                crawler = crawler->children[ind];

                if(crawler->endOfWord) return word.substr(0,i+1);//smallest prefix present on trie.
            }

            return word;
        }

    string replaceWords(vector<string>& dictionary, string sentence) {
        
        string ans ;
        trieNode * root = getNode();
        for(auto word : dictionary) insert(word,root);

        string curr_word;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' '){
                curr_word += sentence[i];
            }
            else{
                if(!curr_word.empty()){
                    ans+= search(curr_word,root) + " ";
                    curr_word.clear();
                } 
            }
        }


            // \U0001f527 Add this to handle the last word
            if (!curr_word.empty()) 
                ans += search(curr_word, root) + " ";


        if(!ans.empty()) ans.pop_back();//removing last space
        return ans;

    }
};