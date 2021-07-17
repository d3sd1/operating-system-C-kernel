practica_num=1
nia_1=100405803
nia_2=100428965
upload_file_name=ssoo_p${practica_num}_${nia_1}_${nia_2}.zip

rm -rf ${upload_file_name}
zip -r ${upload_file_name} .
python probador_ssoo_p${practica_num}.py ${upload_file_name}