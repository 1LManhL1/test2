#include<iostream>
#include<string>
using namespace std;
typedef struct node{
    node *leftchild,*rightchild;
    int id;
}node;
node *root;
node *makenode(int v){
    node *tmp=new node[1];
    tmp->leftchild=NULL;
    tmp->rightchild=NULL;
    tmp->id=v;
    return tmp;
}
node *insert(node *r,int v){
    if(r==NULL) r=makenode(v);
    else if(v<r->id){
        r->leftchild=insert(r->leftchild,v);
    }
    else if(v>r->id){
        r->rightchild=insert(r->rightchild,v);
    }
    return r;
}
node *search(node *r,int v){
    if(r==NULL) return NULL;
    if(r->id==v) return r;
    else if(v<r->id) return search(r->leftchild,v);
    else return search(r->rightchild,v);
}
node *findmin(node *r){
    if(r==NULL) return NULL;
    node *lmin=findmin(r->leftchild);
    if(lmin!=NULL) return lmin;
    return r;
}
node *del(node *r,int v){
    if(r==NULL) return NULL;
    else if(v<r->id) r->leftchild=del(r->leftchild,v);
    else if(v>r->id) r->rightchild=del(r->rightchild,v);
    else {
        if(r->leftchild!=NULL && r->rightchild!=NULL){
            node *tmp=findmin(r->rightchild);
            r->id=tmp->id;
            r->rightchild=del(r->rightchild,tmp->id);
        }
        else{
            node *tmp=r;
            if(r->leftchild==NULL) {
                r=r->rightchild;
            }
            else r=r->leftchild;
            delete tmp;
        }
    }
    return r;
}
void inorder(node *r){
    if(r==NULL) return;
    inorder(r->leftchild);
    cout<<r->id<<" ";
    inorder(r->rightchild);
}
int main(){
    while(1){
        int c;
        cin>>c;
        if(c==-1) break;      
        else root=insert(root,c);
    }
    while(1){
        string x;
        cin>>x;
        if(x=="$remove"){
            int c;cin>>c;
            if(search(root,c)==NULL) cout<<0<<endl;
            else {
                root=del(root,c);
                cout<<1<<endl;
            }
        }
        else if(x=="$find"){
            int c;cin>>c;
            if(search(root,c)==NULL) cout<<0<<endl;
            else{
                cout<<1<<endl;
            }
        }
        else if(x=="$insert"){
            int c;cin>>c;
            if(search(root,c)==NULL) {
                root=insert(root,c);
                cout<<1<<endl;
            }
            else cout<<0<<endl;
        }
        else if(x=="*") break;
    }
    //blesss
}
