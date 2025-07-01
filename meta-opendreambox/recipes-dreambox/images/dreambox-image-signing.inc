python dreambox_sign_image() {
    from oe.gpg_sign import get_signer
    from glob import glob

    if d.getVar('PACKAGE_FEED_SIGN', True) == '1':
        signer = get_signer(d, d.getVar('PACKAGE_FEED_GPG_BACKEND', True))
    else:
        signer = None

    deploy_dir_image = d.getVar('DEPLOY_DIR_IMAGE', True)
 
    if signer:
        files = glob(os.path.join(deploy_dir_image, "*.tar.xz")) + \
                glob(os.path.join(deploy_dir_image, "*.bin")) + \
                glob(os.path.join(deploy_dir_image, "*.nfo"))

        for f in files:
            if os.path.isfile(f):
                bb.note("Signing %s" % f) 
                signer.detach_sign(f,
                                    d.getVar('PACKAGE_FEED_GPG_NAME', True),
                                    d.getVar('PACKAGE_FEED_GPG_PASSPHRASE_FILE', True),
                                    output_suffix="sig",
                                    use_sha256=True)
}

IMAGE_POSTPROCESS_COMMAND += "dreambox_sign_image;"
