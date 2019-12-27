#!/bin/bash
#First HomeWork in linux course
curl https://api.blockcypher.com/v1/btc/main > main_blockchain
api_error=22 # totally random
no_connection_error=23 # totally random

if [[ $(cat main_blockchain) == *error* ]]; then
  cat main_blockchain | sed 's/[{}\"]//g'
  exit $api_error
fi

if [ ! -s main_blockchain ]; then
  rm main_blockchain
  echo "Connection to blockcypher couldn't no be established"
  exit $no_connection_error
fi

num_of_blocks=$(cat main_blockchain | grep '"height": ' | grep -Eo '[0-9]{1,8}')
sub_command="sed 's/[,\"\ ]//g'"
echo num of blocks: $num_of_blocks
rm main_blockchain

if [ -e bitcoin_db.txt ]; then
    rm bitcoin_db.txt
fi

for i in {0..9}
do
  echo Fetch block no. $((num_of_blocks - i))
  curl https://api.blockcypher.com/v1/btc/main/blocks/$(expr $num_of_blocks - $i) > temp.file 2> /dev/null
  cat temp.file | grep "hash" | eval $sub_command  >> bitcoin_db.txt
  cat temp.file | grep "height" | eval $sub_command >> bitcoin_db.txt
  cat temp.file | grep "total" | eval $sub_command >> bitcoin_db.txt
  cat temp.file | grep "time" | eval $sub_command >> bitcoin_db.txt
  cat temp.file | grep "relayed_by" | eval $sub_command >> bitcoin_db.txt
  cat temp.file | grep "prev_block\"" | eval $sub_command >> bitcoin_db.txt
  echo "" >> bitcoin_db.txt
done

rm temp.file
