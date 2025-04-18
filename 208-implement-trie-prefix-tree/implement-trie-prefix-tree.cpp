class Trie {
public:


 //ye trieNode banao
    struct trieNode{
        bool isEndOfWord;
        
        trieNode *children[26]; //26 nodes ki array hogi ek trieNode ke paas whose name is chldren
        
    };
    
    
    
    //custom fn to make a new node 
    trieNode * makeNewNode(){
        trieNode * node = new trieNode();
        
        node->isEndOfWord = false;
        
        for(int i=0;i<26;i++) node->children[i]= NULL;
        
        return node;
    }
    
    
trieNode * root;


    Trie() {
        root = makeNewNode();
    }
    
    void insert(string word) {
         trieNode *crawler = root;
        
        for(int i=0;i<word.size();i++){
            int ind =word[i]-'a';
            if(!crawler->children[ind])
                crawler->children[ind] = makeNewNode();
            
            crawler = crawler->children[ind];
        }
        
        crawler->isEndOfWord =true;
    }
    
    bool search(string word) {
         trieNode *crawler = root;
        
        for(int i=0;i<word.size();i++){
            int ind =word[i]-'a';
            if(!crawler->children[ind])
                    return false;
            
            crawler = crawler->children[ind];
        }
        
        return (crawler!=NULL && crawler->isEndOfWord );
    }
    
    bool startsWith(string prefix) {
         trieNode *crawler = root;
        int i=0;
        for(i=0;i<prefix.size();i++){
            int ind =prefix[i]-'a';
            if(!crawler->children[ind])
                return false;
            
            crawler = crawler->children[ind];
        }
        
        if(i==prefix.size()) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */