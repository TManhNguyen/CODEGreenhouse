import { Disclosure } from '@headlessui/react'
import { SITE_NAME } from '../../lib/constants'

type Props = {
  socketStatus: string
}

const Header = ({
  socketStatus
}: Props) => {
  return (
    <Disclosure as="nav" className="bg-green-400">
      {({ open }) => (
        <>
          <div className="max-w-7xl mx-auto px-8">
            <div className="relative flex items-center justify-between h-20">

              <div className="flex-1 flex items-center justify-center sm:items-stretch sm:justify-start">
                <div className="flex-shrink-0 flex items-center gap-2">
                  <span className="w-8 h-8 bg-gray-100 rounded"></span>
                  <span className="text-white font-bold text-2xl">{ SITE_NAME }</span>
                </div>
                
                <div className="flex-grow" />
                <div className="flex-shrink-0 flex items-center">
                <button className="max-w-xs transition bg-green-500 rounded-full flex items-center text-sm active:ring-2 active:ring-blue-300 py-2 px-4 lg:rounded-full lg:hover:bg-green-600">
                  <span className="text-white text-base font-medium lg:block">
                    {socketStatus}
                  </span>
                  {/* <CheckCircleIcon
                    className="hidden flex-shrink-0 h-5 w-5 ml-1 text-white lg:block"
                    aria-hidden="true"
                  /> */}
                </button>    
              </div>

              </div>
            </div>
          </div>
        </>
      )}
    </Disclosure>
  )
}

export default Header