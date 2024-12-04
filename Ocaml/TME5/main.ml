type 'a htree = 
	| Leaf of int * 'a
	| Branch of int * 'a htree * 'a htree
;;

let t_msg = Branch(17,Leaf(8,'A'),Branch(9,Branch(4,Branch(2,Leaf(1,'C'),Leaf(1,'G')),
		Branch(2,Leaf(1,'H'),Leaf(1,'F'))),
	Branch(5,Branch(2,Leaf(1,'E'),Leaf(1,'D')),
		Leaf(3,'B'))))

let msg = ['A';'A';'B';'A';'C';'B';'A';'G';'H';'A';'A';'F';'E';'A';'D';'B';'A']
let msg_01 = [0;0;1;1;1;0;1;0;0;0;1;1;1;0;1;0;0;1;1;0;1;0;0;0;1;0;1;1;1;1;0;0;
0;1;1;0;1;1;1;1;0]

