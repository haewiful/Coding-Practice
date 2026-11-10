echo "git add"
git add PG_$1.$2
echo "git commit"
git commit -m $1
echo "git push"
git push
