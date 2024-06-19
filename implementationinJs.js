class node{
    constructor(key , val){
        this.key = key;
        this.val= val;
        this.next = null;
    }
};
class linkedlist{
    constructor(){
        this.head = null;
    }

    addAtHead(key , val){
        let temp= new node(key , val);
        if(this.head == null){
            this.head= temp;
            return;
        }else{
            temp.next = this.head;
            this.head = temp;
        }
        return;
    }
    deleteAtHead(){
        if(this.head== null)return ;
        let delnode = this.head;
        this.head = this.head.next;
        delnode.next = null;
    }
    display(){
        let temp= this.head;
        while(temp){
            console.log(temp.key);
            temp= temp.next;
        }
    }
};
class HashMap{
    constructor(){
        this.lamdaFactorThresold = 0.5;
        this.maxsize=2;
        this.currsize=0;
        this.arr =  Array(this.maxsize);
        for(let i=0; i<this.maxsize; i++){
            this.arr[i] = new linkedlist();
        }
    }
    hashfunction(key){

        let ans =0;
        let pow = 101;
        let p =1;
        let c = this.maxsize;

        for(let i=0; i<key.length; i++){
            ans = ((ans%c) + ( (this.ascii(key,i)%c) * (pow%c) )%c )%c;
            p= (p %c * pow%c)%c ;
            
        }
        return ans;
    }
    ascii(key, idx){
        return key.charCodeAt(idx);
    }
    display(){
        for(let i=0; i<this.maxsize ; i++){
            let temp = this.arr[i].head;
            let str = i + "->";
            while(temp != null){
                str+= temp.key +","+ temp.val + "-";
                temp= temp.next;
            }
            console.log(str);
        }
        console.log("**************");
    }
    insert(key, val){
        let present = this.search(key);
        if(present){
            this.update(key,val);
            return;
        }
        let newLoadFactor= ((this.currsize +1) / this.maxsize );
  
        if(newLoadFactor > this.lamdaFactorThresold){
            this.rehash();
        }
        let arridx = this.hashfunction(key);
        this.arr[arridx].addAtHead(key,val);
        this.currsize +=1;
    }
    update(key, val){
        let bucketidx = this.hashfunction(key);
        let temp = this.arr[bucketidx].head;
        while(temp){
            if(temp.key == key){
                temp.val = val;
                return;
            }
            temp= temp.next;
        }
    }
    remove(key){
        let present = this.search(key);
        // present is val to the key
        if(!present){
            console.log(" desired key is not fount");
            return;
        }
        let bucketidx = this.hashfunction(key);
        let temp = this.arr[bucketidx].head;
        if(temp.val == present){
            this.arr[bucketidx].deleteAtHead();
            this.currsize = this.currsize- 1;
            let loadFactor = this.currsize / this.maxsize;
            if(loadFactor< this.lamdaFactorThresold){
                this.rehash(0.5);
            }
            return;
        }
        while(temp.next){
            if(temp.next.val == present){
                let nodetoDel = temp.next;
                temp.next = nodetoDel.next;
                nodetoDel.next = null;
                this.currsize = this.currsize- 1;
                let loadFactor = (this.currsize / this.maxsize);
                if(loadFactor< this.lamdaFactorThresold){
                this.rehash(0.5);
                return;
            }
            temp = temp.next;
            }
        }
    }
    search(key){
        let arridx = this.hashfunction(key);
        let temp = this.arr[arridx].head;
        while(temp != null){
            if(temp.key == key){
                return temp.val;
            }
            temp= temp.next;
        }
        return undefined;
    }

    rehash(factor =2){
        this.maxsize *= factor; // double the capacity of the arr

        const newArr = Array(this.maxsize);// new array with updated capacity

        for(let i = 0; i < this.maxsize; i++) {
            newArr[i] = new linkedlist();
        }

        const oldArr = this.arr; 


        for(let i=0; i<oldArr.length ; i++){
            let temp = oldArr[i].head;
            while(temp != null){
                let key = temp.key;
                let val = temp.val;
                let arridx = this.hashfunction(key);
                newArr[arridx].addAtHead(key,val);
                temp= temp.next;
            }
        }
        this.arr = newArr;
    }
} 

let hm = new HashMap();
hm.insert("mango", 10);
hm.insert("banana", 3);
hm.insert("apple", 4);
hm.display();
hm.insert("banana", 23);
hm.display();
