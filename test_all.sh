
# Push swap tester : 

# avec le générateur de tharchen : genstack.pl
# effectue $seq_max fois push swap pour chaque 5, 100 et 500 nombres
# garde le pire cas ( le plus grand nombres d'opérations) et le compare aux notations
# pour évalué sa notes.

#* ------------------------------
# CHANGER DE CHECKER : 			-
#* ------------------------------
#								-
#checker="./checker_linux"
checker="./checker"
#								-
#* ------------------------------

INT_MIN=-2147483648
INT_MAX=2147483647

# Nombre total de test pour chaque partie
seq_max=50

# autres variables 
max_5=0
max_50=0
max_100=0
max_500=0
result=0

#* ------------------------------
# test pour 5 nombres			-
#* ------------------------------
for i in `seq 1 $seq_max`;
do
	ARG=`./genstack.pl 5 $INT_MIN $INT_MAX`
	let "result = `./push_swap $ARG | wc -l`"
	ok=`./push_swap $ARG | $checker $ARG`
	if [ $ok = "KO" ]; then
		echo "$ok for $ARG"
	fi
	if [ $max_5 -lt $result ]; then
		let "max_5 = $result"
		BADARG_5=$ARG
	fi
	if [ $max_5 = 12 ]; then
		echo "for $ARG"
	fi
done

#* ------------------------------
# test pour 100 nombres			-
#* ------------------------------
for i in `seq 1 $seq_max`;
do
	ARG=`./genstack.pl 100 $INT_MIN $INT_MAX`
	let "result = `./push_swap $ARG | wc -l`"
	ok=`./push_swap $ARG | $checker $ARG`
	if [ $ok = "KO" ]; then
		echo "$ok for $ARG"
	fi
	if [ $max_100 -lt $result ]; then
		let "max_100 = $result"
		BADARG_100=$ARG
	fi
done

#* ------------------------------
# test pour 500 nombres			-
#* ------------------------------
for i in `seq 1 $seq_max`;
do
	ARG=`./genstack.pl 500 $INT_MIN $INT_MAX`
	let "result = `./push_swap $ARG | wc -l`"
	ok=`./push_swap $ARG | $checker $ARG`
	if [ $ok = "KO" ]; then
		echo "$ok for $ARG"
	fi
	if [ $max_500 -lt $result ]; then
		let "max_500 = $result"
		BADARG_500=$ARG
	fi
done


# resultats attendus :
# 
# pour 5 nombre moins de 12 opérations
# ----------------------------------------------------- 
if [ $max_5 -lt 12 ]; then 
	echo -e "\e[92mpour 5 nombres   : $max_5/12	=> OK\e[0m"
else 
	echo -e " \e[31mpour 5 nombres : $max_5/12	=> KO\e[0m"
fi


# pour 100 nombres : les 5 palliers de notations
# ----------------------------------------------------- 
if [ $max_100 -lt 700 ]; then 
	echo -e "\e[92mpour 100 nombres : $max_100/700	=> OK	5/5 Badassss \e[0m"
elif [ $max_100 -lt 900 ]; then
	echo -e "\e[32mpour 100 nombres : $max_100/900	=> OK	4/5	- de 700 pour 5\e[0m"
elif [ $max_100 -lt 1100 ]; then
	echo -e "\e[36mpour 100 nombres : $max_100/1100	=> OK	3/5	- de 900 pour 4\e[0m"
elif [ $max_100 -lt 1300 ]; then
	echo -e "\e[93mpour 100 nombres : $max_100/1300	=> OK	2/5	- de 1100 pour 3\e[0m"
elif [ $max_100 -lt 1500 ]; then
	echo -e "\e[31mpour 100 nombres : $max_100/1500	=> OK	1/5	- de 1300 pour 2\e[0m"
else
	echo -e "\e[91mpour 100 nombres : $max_100/1500	=> KO	0/5	- de 1500 pour 1 let's go !!!!\e[0m"
fi
#echo -e "BADEST ARG = $BADARG_100"



# pour 500 nombres : les 5 palliers de notations
# ----------------------------------------------------- 
if [ $max_500 -lt 5500 ]; then 
	echo -e "\e[92mpour 500 nombres : $max_500/5500	=> OK	5/5 Badassss \e[0m"
elif [ $max_500 -lt 7000 ]; then
	echo -e "\e[32mpour 500 nombres : $max_500/7000	=> OK	4/5	- de 5500 pour 5\e[0m"
elif [ $max_500 -lt 8500 ]; then
	echo -e "\e[36mpour 500 nombres : $max_500/8500	=> OK	3/5	- de 7000 pour 4\e[0m"
elif [ $max_500 -lt 10000 ]; then
	echo -e "\e[93mpour 500 nombres : $max_500/10000	=> OK	2/5	- de 8500 pour 3\e[0m"
elif [ $max_500 -lt 11500 ]; then
	echo -e "\e[31mpour 500 nombres : $max_500/11500	=> OK	1/5	- de 10000 pour 2\e[0m"
else
	echo -e "\e[91mpour 500 nombres : $max_500/11500	=> KO	0/5	- de 11500 pour 1 let's go !!!!\e[0m"
fi
#echo -e "BADEST ARG = $BADARG_500"