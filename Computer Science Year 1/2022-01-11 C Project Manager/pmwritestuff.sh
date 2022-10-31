#!/bin/bash
case $1 in
	pm)
		case $2 in
			write)
				nano $3
				;;
		esac

		case $2 in
			rename)
				mv $3 $4
				;;
		esac

		case $2 in
			copy)
				cp $3 $4
				;;
		esac
esac
