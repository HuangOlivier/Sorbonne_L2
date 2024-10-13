function usage() {
    echo "Usage : $0 <fichier>"
    exit 1
}

if [ $# -ne 1 ]; then
    usage 
fi

if test -w $1; then
    usage 
fi

