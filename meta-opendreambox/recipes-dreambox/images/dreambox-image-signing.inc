python do_image_sign() {
    from oe.gpg_sign import get_signer
    from glob import glob

    if d.getVar('PACKAGE_FEED_SIGN', True) == '1':
        signer = get_signer(d, d.getVar('PACKAGE_FEED_GPG_BACKEND', True))
    else:
        signer = None

    deploy_dir_image = d.getVar('DEPLOY_DIR_IMAGE', True)
    gpg_key_id = d.getVar('PACKAGE_FEED_GPG_NAME', True)
    gpg_pass_file = d.getVar('PACKAGE_FEED_GPG_PASSPHRASE_FILE', True)
 
    if signer:
        files = glob(os.path.join(deploy_dir_image, "*.tar.xz")) + \
                glob(os.path.join(deploy_dir_image, "*.bin")) + \
                glob(os.path.join(deploy_dir_image, "*.nfo"))

        bb.note("GPG key id: %s, passphrase file: %s" % (gpg_key_id, gpg_pass_file))
        for f in files:
            if os.path.isfile(f):
                bb.note("sign file %s" % f)
                signer.detach_sign(f, gpg_key_id, gpg_pass_file,
                                    output_suffix="sig", use_sha256=True)
    else:
        bb.note("GPG signing is disabled!")
}

addtask image_sign after do_image_complete before do_image_qa
do_image_sign[nostamp] = "1"
do_image_sign[dirs] = "${DEPLOY_DIR_IMAGE}"
