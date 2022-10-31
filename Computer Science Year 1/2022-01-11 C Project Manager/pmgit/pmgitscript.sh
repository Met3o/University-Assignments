#!/bin/bash
count=$#
count2=0
case $1 in
	init)
		git init $2
		;;
esac

case $1 in
	add)
		git add $2
		;;
esac

case $1 in
	commit)
		git commit $2
		;;
esac

case $1 in
	push)
		git push --set-upstream origin master
		;;
esac

case $1 in
	username)
		for var in "$@"
		do
			if [[ $var == 'pmgit' ]]
			then
				continue
			fi

			if [[ $var == 'username' ]]
			then
				continue
			fi
			echo $@
			personName+=$var" "
		done
		git config --global user.name = $personName
		echo "Set username to:		" $personName
		;;
esac

case $1 in
	email)
		git config --global user.email = $2
		echo "Successfully set email to:	" $2
		;;

esac
