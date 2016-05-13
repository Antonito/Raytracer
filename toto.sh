echo "============"
echo "$1" | sed 's/\+/\n\+/g;s/-/\n-/g' | rev | grep -v "^t" | sort | rev | sed ':a;N;$!ba;s/\n//g' | sed 's/\+/ \+ /g' | sed 's/-/ - /g' | sed 's/\// \/ /g' | sed "s/\*/ × /g" | sed "s/\^/ \^ /g"
echo "============"
res=$(echo "$1" | sed 's/\+/\n\+/g;s/-/\n-/g' | rev | grep "^t" | sort | sed 's/..//' | rev | sed ':a;N;$!ba;s/\n//g' | sed 's/\+/ \+ /g' | sed 's/-/ - /g' | sed 's/\// \/ /g' | sed "s/\*/ × /g" | sed "s/\^/ \^ /g")
echo "t * $res"
echo "============"
for i in {2..100}
do
	res=$(echo "$1" | sed 's/\+/\n\+/g;s/-/\n-/g' | rev | grep "^$(echo $i | rev)\^t" | sort | sed "s/^$(echo $i | rev)\^t.//" | rev | sed ':a;N;$!ba;s/\n//g' | sed 's/\+/ \+ /g' | sed 's/-/ - /g' | sed 's/\// \/ /g' | sed 's/\*/ × /g' | sed 's/\^/ \^ /g')
	#  | sed 's/\+/ \+ /g' | sed 's/-/ - /g' | sed 's/\// \/ /g' | sed 's/\*/ \* /g'
	if [ -z "$res" ]
	then
		exit 0
	fi
	echo "$(echo $res | sed -r 's/(.).*$/\1/') t ^ $i * $(echo $res | sed 's/.//')"
	echo "==============="
done
