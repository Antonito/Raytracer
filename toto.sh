echo "============"
echo "$1" | sed 's/\+/\n\+/g;s/-/\n-/g' | rev | grep -v "^t" | sort | rev | sed ':a;N;$!ba;s/\n//g' | sed 's/\+/ \+ /g' | sed 's/-/ - /g' | sed 's/\// \/ /g' | sed "s/\*/ × /g" | sed "s/\^/ \^ /g" | sed 's/a/ray->pos.x/g' | sed 's/b/ray->pos.y/g' | sed 's/c/ray->pos.z/g' | sed 's/k/ray->dir.x/g' | sed 's/l/ray->dir.y/g' | sed 's/m/ray->dir.z/g'
echo "============"
res=$(echo "$1" | sed 's/\+/\n\+/g;s/-/\n-/g' | rev | grep "^t" | sort | sed 's/..//' | rev | sed ':a;N;$!ba;s/\n//g' | sed 's/\+/ \+ /g' | sed 's/-/ - /g' | sed 's/\// \/ /g' | sed "s/\*/ × /g" | sed "s/\^/ \^ /g" | sed 's/a/ray->pos.x/g' | sed 's/b/ray->pos.y/g' | sed 's/c/ray->pos.z/g' | sed 's/k/ray->dir.x/g' | sed 's/l/ray->dir.y/g' | sed 's/m/ray->dir.z/g')
echo "t * $res"
echo "============"
for i in {2..100}
do
	res=$(echo "$1" | sed 's/\+/\n\+/g;s/-/\n-/g' | rev | grep "^$(echo $i | rev)\^t" | sort | sed "s/^$(echo $i | rev)\^t.//" | rev | sed ':a;N;$!ba;s/\n//g' | sed 's/\+/ \+ /g' | sed 's/-/ - /g' | sed 's/\// \/ /g' | sed 's/\*/ × /g' | sed 's/\^/ \^ /g' | sed 's/a/ray->pos.x/g' | sed 's/b/ray->pos.y/g' | sed 's/c/ray->pos.z/g' | sed 's/k/ray->dir.x/g' | sed 's/l/ray->dir.y/g' | sed 's/m/ray->dir.z/g')
	#  | sed 's/\+/ \+ /g' | sed 's/-/ - /g' | sed 's/\// \/ /g' | sed 's/\*/ \* /g'
	for i in {100..2}
	do
		let "j=$i-1"
		res=$(echo $res | sed -r "s/([^ ]*) \^ $i/\1 × \1 ^ $j/g")
	done
	res=$(echo $res | sed -r "s/([^ ]*) \^ 1/\1/g")
	if [ -z "$res" ]
	then
		exit 0
	fi
	echo "$(echo $res | sed -r 's/(.).*$/\1/') t ^ $i * $(echo $res | sed 's/.//')"
	echo "==============="
done
