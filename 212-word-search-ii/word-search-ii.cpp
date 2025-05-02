class Solution {
public:

    vector<string> res; 

    int dx[4] = {-1,1,0,0};
    int dy[4]=  {0,0,1,-1};

    struct trieNode{
        bool endOfWord;
        trieNode * children[26];
        string word; //******
    };

    trieNode *getNode(){
        trieNode * temp = new trieNode();
        temp->endOfWord = false;
        for(int i=0;i<26;i++){
            temp->children[i] = NULL;
        }

        temp->word = ""; //jab new node create ho, toh empty word bhi milega. 
        return temp;
    }



    void insert(trieNode * root,string str){
        trieNode * pCrawl = root;

        for(char ch: str){
            
            int ind = ch-'a';
            if(!pCrawl->children[ind]) pCrawl->children[ind] = getNode();

            pCrawl = pCrawl->children[ind];

         }
         pCrawl->endOfWord = true;
         pCrawl->word = str;
    }


    void dfs(vector<vector<char>> &board, int i, int j, trieNode *root){

        // if(i<0||i>=board.size()|| j<0|| j>=board[0].size() || board[i][j]=='$'|| 
        //         !root->children[  board[i][j]-'a' ] )   return ;
    if (!root || !root->children[board[i][j] - 'a']) return;
        root = root->children[ board[i][j]-'a' ];

        if(root->endOfWord == true){
            res.push_back(root->word);
            root->endOfWord = false; //end milgaya word ka fir bhi mark it as false and rukna nahi h.
        }

        char temp = board[i][j];//store before marking visited.

        board[i][j] = '$';//mark it as visited

        for(int k=0;k<4;k++){
            int newx = dx[k]+i;
            int newy = dy[k]+j;
            if(newx>=0 && newx<board.size() &&  newy>=0 &&  newy<board[0].size() &&  board[newx][newy]!='$' &&
                root->children[  board[newx][newy]-'a' ]!=NULL )   
                                        dfs(board,newx,newy,root);
        }

        board[i][j] = temp ; // backtrack. 


    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        trieNode * root = getNode(); // make root trieNode

        //insert all words in trie. 
        for(auto word: words){
            insert(root,word);
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char ch = board[i][j];

                if(root->children[ch-'a']) dfs(board,i,j,root);
            }
        }
    return res;
    }
};