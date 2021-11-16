#!/bin/bash

# SD device
DEVICE="$1"

BOOT_MP="/tmp/$$-boot"

# Print error message with time.
err() {
    echo "[$(date +'%Y-%m-%dT%H:%M:%S%z')]: $@" >&2
}

# Command execution function
execute() {
    $* >/dev/null
    if [[ $? -ne 0 ]]; then
        echo
        err "-> ERROR: failed to execute $* !"
        echo
        exit 1
    fi
}

check_existence_of_needed_files() {
    echo "Checking existence of needed files..."

    if [[ ! -d ./image ]]; then
        err "ERROR: failed to find ./image directory."
        err "Error to exit!"
        exit 1
    fi
}

partition_sd_card() {
    echo "Partitioning SD card..."

    # umount them in case mounted alraady.
    umount_sd_partitions

    # Clear the head of this SD card.
    execute "dd if=/dev/zero of=${DEVICE} bs=1024 count=1024"

    sleep 5 #FIXME Make sure partition is finished
    echo "Done!"
}

format_sd_partitions() {
    echo "-> formating sd partition..."
    mkfs.vfat -F 32 ${DEVICE}
    if [[ $? -ne 0 ]]; then
        echo
        err "-> ERROR: formating sd partition failed!"
        echo
        exit 1
    fi
}

umount_sd_partitions() {
    echo "Umounting partitions..."
    for i in $(cat /proc/mounts | grep ${DEVICE} | awk '{print $1}'); do
        umount -vl $i > /dev/null 2>&1
    done
    echo "done!"
}

burning_program() {
    if [[ -e $1 ]]; then
        execute  "dd if=/image/led.imx of=/dev/sdb bs=1024 seek=2"
        echo "done!...."
    fi
}

# Program main function
main() {
    echo "System time: $(date "+%H:%M:%S")"

    echo -e "\n1/3:"
    check_existence_of_needed_files
    echo "2% done!"

    echo -e "\n2/3:"
    partition_sd_card
    format_sd_partitions
    echo "3% done!"

    echo -e "\n3/3:"
    burning_program
    echo "90% done!"

    echo ""
    umount_sd_partitions

    echo ""
    echo "System time: $(date "+%H:%M:%S")"
    echo "Make progrm done!"
    echo "100% done!"
}

main
